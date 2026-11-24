"""Build each standalone C solution and execute the original and additional cases."""
import argparse
import json
import os
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FLAGS = ["-std=c11", "-Wall", "-Wextra", "-pedantic"]
DESCRIPTIVE = {
    (50, 2): "The expected field explains the indentation. Sample 1 supplies the literal pattern.",
    (52, 1): "The expected field describes a pattern. The separate layout check uses the displayed statement.",
    (54, 1): "The expected field describes a pattern. The separate layout check uses the displayed statement.",
    (126, 1): "The example omits the file contents and uses a placeholder. A concrete two-line fixture checks the behavior.",
    (142, 1): "The example gives neither student records nor literal output. A five-record fixture checks the table.",
}
DISCREPANCIES = {
    (4, 1): "At radius 7, 2πr rounds to 43.98. The listed circumference is 43.96.",
    (9, 2): "Annual compounding gives 5000 × (1.07³ − 1) = 1125.215, or 1125.22 rounded to cents.",
    (44, 1): "The first three terms are 1 + 3/4 + 5/6. Their sum rounds to 2.6 at one decimal place.",
    (45, 1): "The first three terms 2/3 + 4/7 + 6/11 sum to approximately 1.78.",
    (45, 2): "Adding 8/15 and 10/19 gives approximately 2.84.",
    (120, 1): "All three examples capitalize each word. Examples 2 and 3 preserve the final period. This solution consistently preserves punctuation, including the period omitted in example 1.",
    (123, 1): "The supplied file has 33 characters including the newline, six whitespace-delimited words, and two lines.",
}
REFERENCE_OUTPUT = {
    (4, 1): "Area=153.94, Circumference=43.98",
    (9, 2): "Simple Interest=1050, Compound Interest=1125.22",
    (44, 1): "Approximate sum: 2.6",
    (45, 1): "Approximate sum: 1.78",
    (45, 2): "Approximate sum: 2.84",
    (120, 1): "I Am Trying To Build Logic.",
    (123, 1): "Characters: 33\nWords: 6\nLines: 2",
}
def sample_case(number, sample, index):
    """Translate file descriptions and record descriptions into concrete fixtures."""
    stdin = sample["input"]
    expected = sample["output"]
    files, outputs = {}, {}
    if number == 121:
        outputs["info.txt"] = "Name: Rahul\nAge: 23\n"
    elif number == 122:
        stdin, files = "", {"info.txt": "Name: Rahul\nAge: 23"}
    elif number == 123:
        stdin, files = "", {"sample.txt": "Hello world\nThis is C programming"}
    elif number == 124:
        stdin, files = "source.txt destination.txt", {"source.txt": "Learning C File Handling"}
        outputs = {"source.txt": files["source.txt"], "destination.txt": files["source.txt"]}
    elif number == 125:
        stdin, files = "This is appended text.", {"data.txt": "Hello world"}
        outputs = {"data.txt": "Hello world\nThis is appended text.\n"}
    elif number == 126:
        if index == 1:
            stdin, files = "sample.txt", {"sample.txt": "First line\nSecond line"}
            expected = "File opened successfully.\nFirst line\nSecond line"
        else:
            stdin = "nofile.txt"
    elif number == 127:
        stdin, files = "", {"input.txt": "Hello World\nC programming"}
        expected, outputs = "", {"output.txt": "HELLO WORLD\nC PROGRAMMING"}
    elif number == 128:
        stdin, files = "", {"text.txt": "Welcome to C language"}
    elif number == 129:
        stdin, files = "", {"numbers.txt": "10 20 30 40 50"}
    elif number == 130:
        stdin = "2\nAsha 101 85\nRavi 102 92"
        outputs = {"students.txt": "Asha 101 85\nRavi 102 92\n"}
    elif number == 142:
        stdin = "Asha 1 90\nRavi 2 85\nAman 3 80\nSita 4 95\nNeha 5 97"
        expected = "Name\tRoll\tMarks\nAsha\t1\t90\nRavi\t2\t85\nAman\t3\t80\nSita\t4\t95\nNeha\t5\t97"
    elif stdin == "No input":
        stdin = ""
    return dict(stdin=stdin, expected=expected, files=files, outputs=outputs)

def execute(executable, case):
    with tempfile.TemporaryDirectory() as directory:
        folder = Path(directory)
        for name, data in case.get("files", {}).items():
            (folder / name).write_bytes(data.encode())
        stdin = case.get("stdin", "")
        if stdin and not stdin.endswith("\n"):
            stdin += "\n"
        result = subprocess.run([executable], input=stdin.encode(), capture_output=True,
                                cwd=folder, timeout=5)
        actual = result.stdout.decode("utf-8").replace("\r\n", "\n").removesuffix("\n")
        expected = case["expected"].removesuffix("\n")
        file_errors = []
        for name, data in case.get("outputs", {}).items():
            path = folder / name
            if not path.exists() or path.read_text(encoding="utf-8") != data:
                file_errors.append(name)
        passed = result.returncode == case.get("exit", 0) and actual == expected and not file_errors
        return dict(passed=passed, actual=actual, expected=expected, exit=result.returncode,
                    file_errors=file_errors)

def verify(question, build, compiler, extra):
    number = question["id"]
    binary = build / ("q" + str(number) + (".exe" if os.name == "nt" else ""))
    compile_result = subprocess.run([compiler, *FLAGS, str(ROOT / question["path"]), "-o",
                                     str(binary), "-lm"], capture_output=True)
    diagnostics = (compile_result.stderr + compile_result.stdout).decode("utf-8", "replace")
    row = dict(id=number, day=question["day"], compiled=compile_result.returncode == 0,
               diagnostics=diagnostics, samples=[], checks=[])
    if not row["compiled"]:
        return row
    for index, sample in enumerate(question["testCases"], 1):
        case = sample_case(number, sample, index)
        outcome = execute(binary, case)
        key = number, index
        if key in DESCRIPTIVE:
            outcome["status"] = "descriptive"
            outcome["note"] = DESCRIPTIVE[key]
            if number in (126, 142) and not outcome["passed"]:
                outcome["status"] = "failed"
        elif outcome["passed"]:
            outcome["status"] = "passed"
        else:
            outcome["status"] = "failed"
            outcome["note"] = DISCREPANCIES.get(key, "")
        row["samples"].append(outcome)
    for case in extra[str(number)]:
        row["checks"].append(execute(binary, case))
    return row

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cc", default="gcc")
    parser.add_argument("--json", type=Path, help="also save detailed results as JSON")
    args = parser.parse_args()
    questions = json.loads((ROOT / "questions.json").read_text(encoding="utf-8"))["questions"]
    extra = json.loads((ROOT / "tests" / "boundary.json").read_text(encoding="utf-8"))
    with tempfile.TemporaryDirectory() as temp, ThreadPoolExecutor(max_workers=4) as pool:
        results = list(pool.map(lambda q: verify(q, Path(temp), args.cc, extra), questions))
    if args.json:
        args.json.write_text(json.dumps(results, ensure_ascii=False, indent=2), encoding="utf-8")
    samples = [s for row in results for s in row["samples"]]
    checks = [s for row in results for s in row["checks"]]
    builds = sum(r["compiled"] and not r["diagnostics"] for r in results)
    print(f"{builds}/{len(results)} warning-free builds")
    for status in ("passed", "failed", "descriptive"):
        print(f"Published samples {status}: {sum(s['status'] == status for s in samples)}")
    print(f"Extra checks passed: {sum(s['passed'] for s in checks)}/{len(checks)}")
    for row in results:
        for index, case in enumerate(row["samples"], 1):
            if case["status"] == "failed":
                print(f"Q{row['id']} sample {index}: {case['actual']!r} vs {case['expected']!r}")
        for index, case in enumerate(row["checks"], 1):
            if not case["passed"]:
                print(f"Q{row['id']} check {index}: {case}")
        if row["diagnostics"]:
            print(row["diagnostics"])
    # An explicitly documented source mismatch is still reported as a failed sample.
    unexpected = any(s["status"] == "failed" and
                     (s["actual"] != REFERENCE_OUTPUT.get((r["id"], i)) or s["exit"] or s["file_errors"])
                     for r in results for i, s in enumerate(r["samples"], 1))
    return int(builds != len(results) or unexpected or not all(s["passed"] for s in checks))

if __name__ == "__main__":
    sys.exit(main())
