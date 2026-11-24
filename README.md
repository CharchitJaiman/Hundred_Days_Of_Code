# Hundred_Days_Of_Code

**UPES 100 Days of Code · C11 · Day 96 of 100**

The first 50 days contain two exercises each. Days 51–96 contain one each. Every solution runs independently and begins with its original question. The code was written with AI assistance for this project. The historical Git dates are simulated.

Exercises, sample cases, and course materials are credited to Soumik Maity and the UPES challenge. [Challenge website](https://maitysoumik.github.io/basic-coding-with-c/) · [Published question bank](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/questions2.json)

## Build and run

From the repository root, compile an individual exercise with GCC. For example, this program adds two integers.

```sh
gcc -std=c11 -Wall -Wextra -pedantic Day01/Question_1.c -o sum -lm
./sum
```

Enter `3 4` to see `Sum = 7`. In Windows PowerShell, use `-o sum.exe` and run `.\sum.exe`. The math library flag supports programs that use functions such as `sqrt` and `pow`.

The question map records the original inputs, expected outputs, topics, and notes. Use the sample notation for each exercise. In the file-handling section, create the named input files in the working directory before running the program. The test runner shows the concrete fixtures and input conventions for descriptions of files or student records. [Question map](questions.json) · [Test runner](tests/verify.py)

## Verification

| Check | Result |
| --- | ---: |
| Warning-free C11 builds | 146 / 146 |
| Published samples attempted | 259 / 259 |
| Published samples matched | 247 |
| Published outputs that differ | 7 |
| Descriptive examples without a literal comparison | 5 |
| Additional boundary, file, and layout checks passed | 153 / 153 |

Run the suite from the repository root with `python tests/verify.py` using Python 3.9+ and GCC on PATH. Add `--json results.json` to save individual results. Each executable runs in an isolated temporary directory. The report explains every discrepancy and identifies the programs with limited sample verification. [Verification report](VERIFICATION.md)

## Historical Git simulation

The daily author and committer dates demonstrate Git date handling. They are simulated release dates and provide no evidence of historical coding, attendance, or submissions. Each daily commit adds that day's solutions. Checkpoint tags mark every tenth day.

On November 24, 2026, the challenge displayed **Day 96, Q146**. Its scheduler starts on August 10 and counts calendar days, including weekends. On September 5 it makes Days 27 and 28 available together and holds at Day 28 through September 10. Day 29 appears on September 11. The script caps its elapsed-day counter before subtracting four days, so Day 96 first appears on November 17 and remains displayed on November 24. The published logic includes no other holiday exceptions. The dates below follow that release logic. They describe the challenge website only. [Scheduler at the source revision](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/script2.js#L383-L601)

Each simulated time uses the Asia/Kolkata offset (`+05:30`). For day *d*, the time is 10:00 plus `(97 × d + 19) mod 580` minutes and `(17 × d) mod 60` seconds. On Days 27 and 28 the minute offsets are 92 and 376 to preserve release order. The final publication merge joins the simulation to the repository's original November 24 README commit.

## Day-wise index

| Day | First displayed in 2026 | Solutions |
| ---: | --- | --- |
| 01 | Aug 10, Mon | [Q1 · Add two numbers](Day01/Question_1.c) · [Q2 · Four arithmetic operations](Day01/Question_2.c) |
| 02 | Aug 11, Tue | [Q3 · Rectangle area and perimeter](Day02/Question_3.c) · [Q4 · Circle area and circumference](Day02/Question_4.c) |
| 03 | Aug 12, Wed | [Q5 · Celsius to Fahrenheit](Day03/Question_5.c) · [Q6 · Swap with a temporary variable](Day03/Question_6.c) |
| 04 | Aug 13, Thu | [Q7 · Swap without a temporary variable](Day04/Question_7.c) · [Q8 · Sum of natural numbers](Day04/Question_8.c) |
| 05 | Aug 14, Fri | [Q9 · Simple and compound interest](Day05/Question_9.c) · [Q10 · Seconds to hours, minutes, and seconds](Day05/Question_10.c) |
| 06 | Aug 15, Sat | [Q11 · Even or odd](Day06/Question_11.c) · [Q12 · Sign of an integer](Day06/Question_12.c) |
| 07 | Aug 16, Sun | [Q13 · Leap year](Day07/Question_13.c) · [Q14 · Vowel or consonant](Day07/Question_14.c) |
| 08 | Aug 17, Mon | [Q15 · Classify a character](Day08/Question_15.c) · [Q16 · Largest of three numbers](Day08/Question_16.c) |
| 09 | Aug 18, Tue | [Q17 · Quadratic roots](Day09/Question_17.c) · [Q18 · Percentage to grade](Day09/Question_18.c) |
| 10 | Aug 19, Wed | [Q19 · Classify a triangle](Day10/Question_19.c) · [Q20 · Weekday by number](Day10/Question_20.c) |
| 11 | Aug 20, Thu | [Q21 · Month length](Day11/Question_21.c) · [Q22 · Profit or loss percentage](Day11/Question_22.c) |
| 12 | Aug 21, Fri | [Q23 · Library fine](Day12/Question_23.c) · [Q24 · Electricity bill](Day12/Question_24.c) |
| 13 | Aug 22, Sat | [Q25 · Switch-based calculator](Day13/Question_25.c) · [Q26 · Count from 1 to n](Day13/Question_26.c) |
| 14 | Aug 23, Sun | [Q27 · Sum of the first n odd numbers](Day14/Question_27.c) · [Q28 · Product of even numbers](Day14/Question_28.c) |
| 15 | Aug 24, Mon | [Q29 · Factorial](Day15/Question_29.c) · [Q30 · Reverse an integer](Day15/Question_30.c) |
| 16 | Aug 25, Tue | [Q31 · Binary representation](Day16/Question_31.c) · [Q32 · Integer palindrome](Day16/Question_32.c) |
| 17 | Aug 26, Wed | [Q33 · Armstrong number](Day17/Question_33.c) · [Q34 · Primality test](Day17/Question_34.c) |
| 18 | Aug 27, Thu | [Q35 · List all factors](Day18/Question_35.c) · [Q36 · Greatest common divisor](Day18/Question_36.c) |
| 19 | Aug 28, Fri | [Q37 · Least common multiple](Day19/Question_37.c) · [Q38 · Digit sum](Day19/Question_38.c) |
| 20 | Aug 29, Sat | [Q39 · Product of odd digits](Day20/Question_39.c) · [Q40 · Binary one's complement](Day20/Question_40.c) |
| 21 | Aug 30, Sun | [Q41 · Swap the outer digits](Day21/Question_41.c) · [Q42 · Perfect number](Day21/Question_42.c) |
| 22 | Aug 31, Mon | [Q43 · Strong number](Day22/Question_43.c) · [Q44 · Odd-numerator series](Day22/Question_44.c) |
| 23 | Sep 01, Tue | [Q45 · Even-numerator series](Day23/Question_45.c) · [Q46 · Square of stars](Day23/Question_46.c) |
| 24 | Sep 02, Wed | [Q47 · Increasing star triangle](Day24/Question_47.c) · [Q48 · Increasing digit prefix](Day24/Question_48.c) |
| 25 | Sep 03, Thu | [Q49 · Right-ending number rows](Day25/Question_49.c) · [Q50 · Indented decreasing stars](Day25/Question_50.c) |
| 26 | Sep 04, Fri | [Q51 · Right-aligned number rows](Day26/Question_51.c) · [Q52 · Vertical star groups](Day26/Question_52.c) |
| 27 | Sep 05, Sat | [Q53 · Expanding and shrinking star rows](Day27/Question_53.c) · [Q54 · Centered star diamond](Day27/Question_54.c) |
| 28 | Sep 05, Sat | [Q55 · Primes up to n](Day28/Question_55.c) · [Q56 · Read and display an array](Day28/Question_56.c) |
| 29 | Sep 11, Fri | [Q57 · Sum an array](Day29/Question_57.c) · [Q58 · Array minimum and maximum](Day29/Question_58.c) |
| 30 | Sep 12, Sat | [Q59 · Count even and odd elements](Day30/Question_59.c) · [Q60 · Count positive, negative, and zero elements](Day30/Question_60.c) |
| 31 | Sep 13, Sun | [Q61 · Linear search](Day31/Question_61.c) · [Q62 · Reverse an array in place](Day31/Question_62.c) |
| 32 | Sep 14, Mon | [Q63 · Concatenate two arrays](Day32/Question_63.c) · [Q64 · Most frequent digit](Day32/Question_64.c) |
| 33 | Sep 15, Tue | [Q65 · Binary search](Day33/Question_65.c) · [Q66 · Insert into a sorted array](Day33/Question_66.c) |
| 34 | Sep 16, Wed | [Q67 · Insert at an index](Day34/Question_67.c) · [Q68 · Delete at an index](Day34/Question_68.c) |
| 35 | Sep 17, Thu | [Q69 · Second largest distinct value](Day35/Question_69.c) · [Q70 · Right rotation](Day35/Question_70.c) |
| 36 | Sep 18, Fri | [Q71 · Read and display a matrix](Day36/Question_71.c) · [Q72 · Matrix sum](Day36/Question_72.c) |
| 37 | Sep 19, Sat | [Q73 · Row sums](Day37/Question_73.c) · [Q74 · Transpose a matrix](Day37/Question_74.c) |
| 38 | Sep 20, Sun | [Q75 · Matrix addition](Day38/Question_75.c) · [Q76 · Matrix symmetry](Day38/Question_76.c) |
| 39 | Sep 21, Mon | [Q77 · Distinct main-diagonal entries](Day39/Question_77.c) · [Q78 · Main-diagonal sum](Day39/Question_78.c) |
| 40 | Sep 22, Tue | [Q79 · Zigzag diagonal traversal](Day40/Question_79.c) · [Q80 · Matrix multiplication](Day40/Question_80.c) |
| 41 | Sep 23, Wed | [Q81 · String length](Day41/Question_81.c) · [Q82 · One character per line](Day41/Question_82.c) |
| 42 | Sep 24, Thu | [Q83 · Vowel and consonant counts](Day42/Question_83.c) · [Q84 · Uppercase conversion](Day42/Question_84.c) |
| 43 | Sep 25, Fri | [Q85 · Reverse a string](Day43/Question_85.c) · [Q86 · String palindrome](Day43/Question_86.c) |
| 44 | Sep 26, Sat | [Q87 · Count spaces, digits, and symbols](Day44/Question_87.c) · [Q88 · Replace spaces with hyphens](Day44/Question_88.c) |
| 45 | Sep 27, Sun | [Q89 · Character frequency](Day45/Question_89.c) · [Q90 · Toggle letter case](Day45/Question_90.c) |
| 46 | Sep 28, Mon | [Q91 · Remove vowels](Day46/Question_91.c) · [Q92 · First repeated letter](Day46/Question_92.c) |
| 47 | Sep 29, Tue | [Q93 · Compare anagrams](Day47/Question_93.c) · [Q94 · Longest word](Day47/Question_94.c) |
| 48 | Sep 30, Wed | [Q95 · String rotation](Day48/Question_95.c) · [Q96 · Reverse each word](Day48/Question_96.c) |
| 49 | Oct 01, Thu | [Q97 · Name initials](Day49/Question_97.c) · [Q98 · Initials and surname](Day49/Question_98.c) |
| 50 | Oct 02, Fri | [Q99 · Reformat a date](Day50/Question_99.c) · [Q100 · Enumerate substrings](Day50/Question_100.c) |
| 51 | Oct 03, Sat | [Q101 · First and last target indices](Day51/Question_101.c) |
| 52 | Oct 04, Sun | [Q102 · Lower bound in a sorted array](Day52/Question_102.c) |
| 53 | Oct 05, Mon | [Q103 · Pivot index](Day53/Question_103.c) |
| 54 | Oct 06, Tue | [Q104 · Pivot integer](Day54/Question_104.c) |
| 55 | Oct 07, Wed | [Q105 · Strict majority element](Day55/Question_105.c) |
| 56 | Oct 08, Thu | [Q106 · Next greater element](Day56/Question_106.c) |
| 57 | Oct 09, Fri | [Q107 · Previous greater element](Day57/Question_107.c) |
| 58 | Oct 10, Sat | [Q108 · Product except self](Day58/Question_108.c) |
| 59 | Oct 11, Sun | [Q109 · Maximum window sum](Day59/Question_109.c) |
| 60 | Oct 12, Mon | [Q110 · Sliding-window maxima](Day60/Question_110.c) |
| 61 | Oct 13, Tue | [Q111 · First negative in each window](Day61/Question_111.c) |
| 62 | Oct 14, Wed | [Q112 · Maximum subarray sum](Day62/Question_112.c) |
| 63 | Oct 15, Thu | [Q113 · Kth smallest value](Day63/Question_113.c) |
| 64 | Oct 16, Fri | [Q114 · Longest substring without repetition](Day64/Question_114.c) |
| 65 | Oct 17, Sat | [Q115 · Lowercase anagrams](Day65/Question_115.c) |
| 66 | Oct 18, Sun | [Q116 · Two-sum indices](Day66/Question_116.c) |
| 67 | Oct 19, Mon | [Q117 · Merge sorted arrays](Day67/Question_117.c) |
| 68 | Oct 20, Tue | [Q118 · Find the missing number](Day68/Question_118.c) |
| 69 | Oct 21, Wed | [Q119 · Find the repeated element](Day69/Question_119.c) |
| 70 | Oct 22, Thu | [Q120 · Capitalize words](Day70/Question_120.c) |
| 71 | Oct 23, Fri | [Q121 · Write a name and age to a file](Day71/Question_121.c) |
| 72 | Oct 24, Sat | [Q122 · Read a file line by line](Day72/Question_122.c) |
| 73 | Oct 25, Sun | [Q123 · Count characters, words, and lines](Day73/Question_123.c) |
| 74 | Oct 26, Mon | [Q124 · Copy a file](Day74/Question_124.c) |
| 75 | Oct 27, Tue | [Q125 · Append a line](Day75/Question_125.c) |
| 76 | Oct 28, Wed | [Q126 · Open and display a file](Day76/Question_126.c) |
| 77 | Oct 29, Thu | [Q127 · Uppercase a text file](Day77/Question_127.c) |
| 78 | Oct 30, Fri | [Q128 · Count vowels and consonants in a file](Day78/Question_128.c) |
| 79 | Oct 31, Sat | [Q129 · Sum and average a file of integers](Day79/Question_129.c) |
| 80 | Nov 01, Sun | [Q130 · Write and read student records](Day80/Question_130.c) |
| 81 | Nov 02, Mon | [Q131 · Enumerate weekdays](Day81/Question_131.c) |
| 82 | Nov 03, Tue | [Q132 · Traffic-light actions](Day82/Question_132.c) |
| 83 | Nov 04, Wed | [Q133 · Month lengths with an enum](Day83/Question_133.c) |
| 84 | Nov 05, Thu | [Q134 · Operation status messages](Day84/Question_134.c) |
| 85 | Nov 06, Fri | [Q135 · Explicit enum values](Day85/Question_135.c) |
| 86 | Nov 07, Sat | [Q136 · Enum-based arithmetic menu](Day86/Question_136.c) |
| 87 | Nov 08, Sun | [Q137 · User roles](Day87/Question_137.c) |
| 88 | Nov 09, Mon | [Q138 · List color names and values](Day88/Question_138.c) |
| 89 | Nov 10, Tue | [Q139 · Integer values of status codes](Day89/Question_139.c) |
| 90 | Nov 11, Wed | [Q140 · Gender field in a structure](Day90/Question_140.c) |
| 91 | Nov 12, Thu | [Q141 · Read and display a student](Day91/Question_141.c) |
| 92 | Nov 13, Fri | [Q142 · Five-student table](Day92/Question_142.c) |
| 93 | Nov 14, Sat | [Q143 · Highest marks](Day93/Question_143.c) |
| 94 | Nov 15, Sun | [Q144 · Pass a structure to a function](Day94/Question_144.c) |
| 95 | Nov 16, Mon | [Q145 · Return the top student](Day95/Question_145.c) |
| 96 | Nov 17, Tue | [Q146 · Employee with a nested joining date](Day96/Question_146.c) |
