CS264 Assignment 2
haowu@cs.nuim.ie

October 15, 2025

1 Submission Instructions

This assignment is 18%, please upload your source code to moodle before 23:59,
22nd-October. Please note that your source code has to be C++, otherwise your
submission will be automatically rejected.

2 Plagiarism

Zero-tolerance policy with plagiarism is applied to this assignment. If your sub-
mission is found to be copied from someone else’s work or machine generated or
downloaded from internet. 0 mark will be given immediately and a case will be
reported to the Department and University.

3 Late Submission

Late submissions will receive cumulative penalties to the awarded mark; 5% for first
day, 15% for second day, 35% for third day, 65% for fourth day. Late submissions
after the fourth day will not be accepted.

4 Writing your own String functions

In this assignment, you need to write your own string functions based on the
following requirements without using built-in C++ string.

1

4.1

length

unsigned int length (const char* str)

[Description]: The length function shall return the length of a string excluding
the '\0' character.

[Example]: length("string") returns 6 and length("string\0") also returns
6.

4.2

copy

char* copy (char* dest, const char* src)

[Description]: The copy function shall copy one string from src (including the
'\0' character) to dest and return the copied string. The copy should happen if
the size of the destination string is large enough to store the copied string, other-
wise the function returns NULL.

[Example]: copy(dest, "string"), when printing dest it should print string
on the screen, if dest has enough space to hold "string".

4.3

indexOf

int indexOf (char c, const char* str)

[Description]: The indexOf function shall return the position of the first oc-
currence of c in a string str. If no such character c is found, then it shall return
−1.

[Example]: indexOf('i', "string"), it should return 3. The call
indexOf('a', "string") should return −1.

4.4

substring

char* substring (int i, int j, const char* str)

[Description]: The substring function shall return a substring of a given string
str. The substring begins with the character at index i upto index j − 1. This
function shall make sure i and j are in the valid range, otherwise it shall return

2

NULL.
[Example]: substring(0, 3, "string") should return "str".

4.5

replace

char* replace (char c, char p, const char* str)

[Description]: The replace function shall return a new string that replaces
every occurrence of c with p in a given string str. If no such character c is found,
then a copy of the string str is returned.

[Example]: replace('i','x', "string"), it should return "strxng".

5 Comments

For each function above, you should write a block of comment to explain what a
function does including its return values and arguments. The comments will be
10% of this assignment.

6 Test Cases

For each function above, you should also consider to write some test cases in other
functions with the following name style:
[function]_name_test_case_[k]
where [function] is a function name and [k] is the number of test case. For
example, the 1st test case for function substring will be substring_test_case_1;
The total number of test cases is depending on you. However, the rule here is you
should have sufficient number of test cases to test each function. The test cases
will be 20% of this assignment.

3

