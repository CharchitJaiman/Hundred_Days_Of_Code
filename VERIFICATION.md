# C11 verification through Day 96

On November 24, 2026, GCC 16.2.0 (MinGW-w64, Windows x86-64) compiled all 146 standalone solutions with `-std=c11 -Wall -Wextra -pedantic` and the math library. The compiler produced zero warnings. All 259 published cases ran. 247 matched, 7 differed, and 5 supplied a description in place of literal output. All 153 additional checks passed. Zero cases were left unexecuted.

The runner compares output after normalizing CRLF and a single final newline. Leading spaces, internal whitespace, punctuation, and line breaks remain significant. File exercises also check the resulting files where specified. Q127 compares the named output file. Q130 receives the two published records as a count followed by whitespace-separated fields. Q142 uses five concrete records because its source provides only a description. Text exercises use the single-byte character conventions of the published examples.

The test runner returns a failure on any compilation diagnostic, unexpected output, missing required file, or failing additional check. For the seven known discrepancies it also checks the program's output against a separate reference result. Each discrepancy still counts as a failed published sample. [Run the verifier](tests/verify.py) · [Additional cases](tests/boundary.json) · [Original examples](questions.json)

## Published sample discrepancies

| Question and sample | Published output | Actual output | Explanation |
| --- | --- | --- | --- |
| [Q4](Day02/Question_4.c), sample 1 | <code>Area=153.94, Circumference=43.96</code> | <code>Area=153.94, Circumference=43.98</code> | At radius 7, 2πr rounds to 43.98. The listed circumference is 43.96. |
| [Q9](Day05/Question_9.c), sample 2 | <code>Simple Interest=1050, Compound Interest=1125.76</code> | <code>Simple Interest=1050, Compound Interest=1125.22</code> | Annual compounding gives 5000 × (1.07³ − 1) = 1125.215, or 1125.22 rounded to cents. |
| [Q44](Day22/Question_44.c), sample 1 | <code>Approximate sum: 3.3</code> | <code>Approximate sum: 2.6</code> | The first three terms are 1 + 3/4 + 5/6. Their sum rounds to 2.6 at one decimal place. |
| [Q45](Day23/Question_45.c), sample 1 | <code>Approximate sum: 1.56</code> | <code>Approximate sum: 1.78</code> | The first three terms 2/3 + 4/7 + 6/11 sum to approximately 1.78. |
| [Q45](Day23/Question_45.c), sample 2 | <code>Approximate sum: 2.22</code> | <code>Approximate sum: 2.84</code> | Adding 8/15 and 10/19 gives approximately 2.84. |
| [Q120](Day70/Question_120.c), sample 1 | <code>I Am Trying To Build Logic</code> | <code>I Am Trying To Build Logic.</code> | All three examples capitalize each word. Examples 2 and 3 preserve the final period. This solution consistently preserves punctuation, including the period omitted in example 1. |
| [Q123](Day73/Question_123.c), sample 1 | <code>Characters: 31<br>Words: 5<br>Lines: 2</code> | <code>Characters: 33<br>Words: 6<br>Lines: 2</code> | The supplied file has 33 characters including the newline, six whitespace-delimited words, and two lines. |

## Descriptive examples

| Question and sample | Treatment |
| --- | --- |
| [Q50](Day25/Question_50.c), sample 2 | The expected field explains the indentation. Sample 1 supplies the literal pattern. |
| [Q52](Day26/Question_52.c), sample 1 | The expected field describes a pattern. The separate layout check uses the displayed statement. |
| [Q54](Day27/Question_54.c), sample 1 | The expected field describes a pattern. The separate layout check uses the displayed statement. |
| [Q126](Day76/Question_126.c), sample 1 | The example omits the file contents and uses a placeholder. A concrete two-line fixture checks the behavior. |
| [Q142](Day92/Question_142.c), sample 1 | The example gives neither student records nor literal output. A five-record fixture checks the table. |

## Results by program

The sample column follows the original case order. Additional checks include fixed-layout regression cases for programs without inputs.

| Day | Program | Published samples | Additional checks passed |
| ---: | --- | --- | ---: |
| 01 | [Q1 · Add two numbers](Day01/Question_1.c) | passed, passed | 1 |
| 01 | [Q2 · Four arithmetic operations](Day01/Question_2.c) | passed, passed | 1 |
| 02 | [Q3 · Rectangle area and perimeter](Day02/Question_3.c) | passed, passed | 1 |
| 02 | [Q4 · Circle area and circumference](Day02/Question_4.c) | failed, passed | 2 |
| 03 | [Q5 · Celsius to Fahrenheit](Day03/Question_5.c) | passed, passed | 1 |
| 03 | [Q6 · Swap with a temporary variable](Day03/Question_6.c) | passed, passed | 1 |
| 04 | [Q7 · Swap without a temporary variable](Day04/Question_7.c) | passed, passed | 1 |
| 04 | [Q8 · Sum of natural numbers](Day04/Question_8.c) | passed, passed | 1 |
| 05 | [Q9 · Simple and compound interest](Day05/Question_9.c) | passed, failed | 2 |
| 05 | [Q10 · Seconds to hours, minutes, and seconds](Day05/Question_10.c) | passed, passed | 1 |
| 06 | [Q11 · Even or odd](Day06/Question_11.c) | passed, passed | 1 |
| 06 | [Q12 · Sign of an integer](Day06/Question_12.c) | passed, passed, passed | 1 |
| 07 | [Q13 · Leap year](Day07/Question_13.c) | passed, passed, passed | 1 |
| 07 | [Q14 · Vowel or consonant](Day07/Question_14.c) | passed, passed | 1 |
| 08 | [Q15 · Classify a character](Day08/Question_15.c) | passed, passed, passed, passed | 1 |
| 08 | [Q16 · Largest of three numbers](Day08/Question_16.c) | passed, passed | 1 |
| 09 | [Q17 · Quadratic roots](Day09/Question_17.c) | passed, passed, passed | 1 |
| 09 | [Q18 · Percentage to grade](Day09/Question_18.c) | passed, passed, passed, passed | 1 |
| 10 | [Q19 · Classify a triangle](Day10/Question_19.c) | passed, passed, passed | 1 |
| 10 | [Q20 · Weekday by number](Day10/Question_20.c) | passed, passed | 1 |
| 11 | [Q21 · Month length](Day11/Question_21.c) | passed, passed | 1 |
| 11 | [Q22 · Profit or loss percentage](Day11/Question_22.c) | passed, passed, passed | 1 |
| 12 | [Q23 · Library fine](Day12/Question_23.c) | passed, passed, passed, passed | 1 |
| 12 | [Q24 · Electricity bill](Day12/Question_24.c) | passed, passed, passed | 1 |
| 13 | [Q25 · Switch-based calculator](Day13/Question_25.c) | passed, passed, passed | 1 |
| 13 | [Q26 · Count from 1 to n](Day13/Question_26.c) | passed, passed | 1 |
| 14 | [Q27 · Sum of the first n odd numbers](Day14/Question_27.c) | passed, passed | 1 |
| 14 | [Q28 · Product of even numbers](Day14/Question_28.c) | passed, passed | 1 |
| 15 | [Q29 · Factorial](Day15/Question_29.c) | passed, passed | 2 |
| 15 | [Q30 · Reverse an integer](Day15/Question_30.c) | passed, passed | 1 |
| 16 | [Q31 · Binary representation](Day16/Question_31.c) | passed, passed | 1 |
| 16 | [Q32 · Integer palindrome](Day16/Question_32.c) | passed, passed | 1 |
| 17 | [Q33 · Armstrong number](Day17/Question_33.c) | passed, passed | 1 |
| 17 | [Q34 · Primality test](Day17/Question_34.c) | passed, passed | 1 |
| 18 | [Q35 · List all factors](Day18/Question_35.c) | passed, passed | 1 |
| 18 | [Q36 · Greatest common divisor](Day18/Question_36.c) | passed, passed | 1 |
| 19 | [Q37 · Least common multiple](Day19/Question_37.c) | passed, passed | 1 |
| 19 | [Q38 · Digit sum](Day19/Question_38.c) | passed, passed | 1 |
| 20 | [Q39 · Product of odd digits](Day20/Question_39.c) | passed, passed | 1 |
| 20 | [Q40 · Binary one's complement](Day20/Question_40.c) | passed, passed | 1 |
| 21 | [Q41 · Swap the outer digits](Day21/Question_41.c) | passed, passed | 1 |
| 21 | [Q42 · Perfect number](Day21/Question_42.c) | passed, passed | 1 |
| 22 | [Q43 · Strong number](Day22/Question_43.c) | passed, passed | 1 |
| 22 | [Q44 · Odd-numerator series](Day22/Question_44.c) | failed, passed | 2 |
| 23 | [Q45 · Even-numerator series](Day23/Question_45.c) | failed, failed | 3 |
| 23 | [Q46 · Square of stars](Day23/Question_46.c) | passed | 1 |
| 24 | [Q47 · Increasing star triangle](Day24/Question_47.c) | passed | 1 |
| 24 | [Q48 · Increasing digit prefix](Day24/Question_48.c) | passed | 1 |
| 25 | [Q49 · Right-ending number rows](Day25/Question_49.c) | passed | 1 |
| 25 | [Q50 · Indented decreasing stars](Day25/Question_50.c) | passed, descriptive | 1 |
| 26 | [Q51 · Right-aligned number rows](Day26/Question_51.c) | passed | 1 |
| 26 | [Q52 · Vertical star groups](Day26/Question_52.c) | descriptive | 1 |
| 27 | [Q53 · Expanding and shrinking star rows](Day27/Question_53.c) | passed | 1 |
| 27 | [Q54 · Centered star diamond](Day27/Question_54.c) | descriptive | 1 |
| 28 | [Q55 · Primes up to n](Day28/Question_55.c) | passed, passed | 1 |
| 28 | [Q56 · Read and display an array](Day28/Question_56.c) | passed, passed | 1 |
| 29 | [Q57 · Sum an array](Day29/Question_57.c) | passed, passed | 1 |
| 29 | [Q58 · Array minimum and maximum](Day29/Question_58.c) | passed, passed | 1 |
| 30 | [Q59 · Count even and odd elements](Day30/Question_59.c) | passed, passed | 1 |
| 30 | [Q60 · Count positive, negative, and zero elements](Day30/Question_60.c) | passed | 1 |
| 31 | [Q61 · Linear search](Day31/Question_61.c) | passed, passed | 1 |
| 31 | [Q62 · Reverse an array in place](Day31/Question_62.c) | passed | 1 |
| 32 | [Q63 · Concatenate two arrays](Day32/Question_63.c) | passed | 1 |
| 32 | [Q64 · Most frequent digit](Day32/Question_64.c) | passed, passed | 1 |
| 33 | [Q65 · Binary search](Day33/Question_65.c) | passed, passed | 1 |
| 33 | [Q66 · Insert into a sorted array](Day33/Question_66.c) | passed | 1 |
| 34 | [Q67 · Insert at an index](Day34/Question_67.c) | passed | 1 |
| 34 | [Q68 · Delete at an index](Day34/Question_68.c) | passed | 1 |
| 35 | [Q69 · Second largest distinct value](Day35/Question_69.c) | passed | 1 |
| 35 | [Q70 · Right rotation](Day35/Question_70.c) | passed | 1 |
| 36 | [Q71 · Read and display a matrix](Day36/Question_71.c) | passed | 1 |
| 36 | [Q72 · Matrix sum](Day36/Question_72.c) | passed | 1 |
| 37 | [Q73 · Row sums](Day37/Question_73.c) | passed | 1 |
| 37 | [Q74 · Transpose a matrix](Day37/Question_74.c) | passed | 1 |
| 38 | [Q75 · Matrix addition](Day38/Question_75.c) | passed | 1 |
| 38 | [Q76 · Matrix symmetry](Day38/Question_76.c) | passed, passed | 1 |
| 39 | [Q77 · Distinct main-diagonal entries](Day39/Question_77.c) | passed, passed | 1 |
| 39 | [Q78 · Main-diagonal sum](Day39/Question_78.c) | passed | 1 |
| 40 | [Q79 · Zigzag diagonal traversal](Day40/Question_79.c) | passed | 1 |
| 40 | [Q80 · Matrix multiplication](Day40/Question_80.c) | passed | 1 |
| 41 | [Q81 · String length](Day41/Question_81.c) | passed, passed | 1 |
| 41 | [Q82 · One character per line](Day41/Question_82.c) | passed | 1 |
| 42 | [Q83 · Vowel and consonant counts](Day42/Question_83.c) | passed | 1 |
| 42 | [Q84 · Uppercase conversion](Day42/Question_84.c) | passed | 1 |
| 43 | [Q85 · Reverse a string](Day43/Question_85.c) | passed | 1 |
| 43 | [Q86 · String palindrome](Day43/Question_86.c) | passed, passed | 1 |
| 44 | [Q87 · Count spaces, digits, and symbols](Day44/Question_87.c) | passed | 1 |
| 44 | [Q88 · Replace spaces with hyphens](Day44/Question_88.c) | passed | 1 |
| 45 | [Q89 · Character frequency](Day45/Question_89.c) | passed | 1 |
| 45 | [Q90 · Toggle letter case](Day45/Question_90.c) | passed | 1 |
| 46 | [Q91 · Remove vowels](Day46/Question_91.c) | passed | 1 |
| 46 | [Q92 · First repeated letter](Day46/Question_92.c) | passed | 1 |
| 47 | [Q93 · Compare anagrams](Day47/Question_93.c) | passed, passed | 1 |
| 47 | [Q94 · Longest word](Day47/Question_94.c) | passed | 1 |
| 48 | [Q95 · String rotation](Day48/Question_95.c) | passed, passed | 1 |
| 48 | [Q96 · Reverse each word](Day48/Question_96.c) | passed | 1 |
| 49 | [Q97 · Name initials](Day49/Question_97.c) | passed | 1 |
| 49 | [Q98 · Initials and surname](Day49/Question_98.c) | passed | 1 |
| 50 | [Q99 · Reformat a date](Day50/Question_99.c) | passed | 1 |
| 50 | [Q100 · Enumerate substrings](Day50/Question_100.c) | passed | 1 |
| 51 | [Q101 · First and last target indices](Day51/Question_101.c) | passed, passed, passed | 1 |
| 52 | [Q102 · Lower bound in a sorted array](Day52/Question_102.c) | passed, passed, passed, passed | 1 |
| 53 | [Q103 · Pivot index](Day53/Question_103.c) | passed, passed, passed | 1 |
| 54 | [Q104 · Pivot integer](Day54/Question_104.c) | passed, passed, passed | 1 |
| 55 | [Q105 · Strict majority element](Day55/Question_105.c) | passed, passed, passed | 1 |
| 56 | [Q106 · Next greater element](Day56/Question_106.c) | passed, passed, passed, passed | 1 |
| 57 | [Q107 · Previous greater element](Day57/Question_107.c) | passed, passed, passed, passed | 1 |
| 58 | [Q108 · Product except self](Day58/Question_108.c) | passed, passed | 1 |
| 59 | [Q109 · Maximum window sum](Day59/Question_109.c) | passed, passed, passed | 1 |
| 60 | [Q110 · Sliding-window maxima](Day60/Question_110.c) | passed, passed | 1 |
| 61 | [Q111 · First negative in each window](Day61/Question_111.c) | passed, passed, passed | 1 |
| 62 | [Q112 · Maximum subarray sum](Day62/Question_112.c) | passed, passed, passed | 1 |
| 63 | [Q113 · Kth smallest value](Day63/Question_113.c) | passed, passed | 1 |
| 64 | [Q114 · Longest substring without repetition](Day64/Question_114.c) | passed, passed, passed | 1 |
| 65 | [Q115 · Lowercase anagrams](Day65/Question_115.c) | passed, passed | 1 |
| 66 | [Q116 · Two-sum indices](Day66/Question_116.c) | passed, passed, passed | 1 |
| 67 | [Q117 · Merge sorted arrays](Day67/Question_117.c) | passed, passed, passed | 1 |
| 68 | [Q118 · Find the missing number](Day68/Question_118.c) | passed, passed, passed | 1 |
| 69 | [Q119 · Find the repeated element](Day69/Question_119.c) | passed, passed, passed | 1 |
| 70 | [Q120 · Capitalize words](Day70/Question_120.c) | failed, passed, passed | 1 |
| 71 | [Q121 · Write a name and age to a file](Day71/Question_121.c) | passed | 1 |
| 72 | [Q122 · Read a file line by line](Day72/Question_122.c) | passed | 1 |
| 73 | [Q123 · Count characters, words, and lines](Day73/Question_123.c) | failed | 2 |
| 74 | [Q124 · Copy a file](Day74/Question_124.c) | passed | 1 |
| 75 | [Q125 · Append a line](Day75/Question_125.c) | passed | 1 |
| 76 | [Q126 · Open and display a file](Day76/Question_126.c) | descriptive, passed | 1 |
| 77 | [Q127 · Uppercase a text file](Day77/Question_127.c) | passed | 1 |
| 78 | [Q128 · Count vowels and consonants in a file](Day78/Question_128.c) | passed | 1 |
| 79 | [Q129 · Sum and average a file of integers](Day79/Question_129.c) | passed | 1 |
| 80 | [Q130 · Write and read student records](Day80/Question_130.c) | passed | 1 |
| 81 | [Q131 · Enumerate weekdays](Day81/Question_131.c) | passed | 1 |
| 82 | [Q132 · Traffic-light actions](Day82/Question_132.c) | passed | 1 |
| 83 | [Q133 · Month lengths with an enum](Day83/Question_133.c) | passed | 1 |
| 84 | [Q134 · Operation status messages](Day84/Question_134.c) | passed | 1 |
| 85 | [Q135 · Explicit enum values](Day85/Question_135.c) | passed | 1 |
| 86 | [Q136 · Enum-based arithmetic menu](Day86/Question_136.c) | passed | 1 |
| 87 | [Q137 · User roles](Day87/Question_137.c) | passed | 1 |
| 88 | [Q138 · List color names and values](Day88/Question_138.c) | passed | 1 |
| 89 | [Q139 · Integer values of status codes](Day89/Question_139.c) | passed | 1 |
| 90 | [Q140 · Gender field in a structure](Day90/Question_140.c) | passed | 1 |
| 91 | [Q141 · Read and display a student](Day91/Question_141.c) | passed | 1 |
| 92 | [Q142 · Five-student table](Day92/Question_142.c) | descriptive | 1 |
| 93 | [Q143 · Highest marks](Day93/Question_143.c) | passed | 1 |
| 94 | [Q144 · Pass a structure to a function](Day94/Question_144.c) | passed | 1 |
| 95 | [Q145 · Return the top student](Day95/Question_145.c) | passed | 1 |
| 96 | [Q146 · Employee with a nested joining date](Day96/Question_146.c) | passed | 1 |
