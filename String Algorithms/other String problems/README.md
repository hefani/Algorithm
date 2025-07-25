# String Algorithms

This folder contains implementations of classic and advanced string algorithm problems from Codeforces and similar platforms. Each solution demonstrates important techniques such as dynamic programming, hashing, palindrome computations, and recursive string equivalence checks.

#Topics Covered

- Dynamic Programming on strings
- Palindrome detection and counting
- String hashing with polynomial rolling hash
- Recursive string equivalence
- Bracket sequence analysis
- Pattern searching and substring checks

 ### Problem Summaries
  
  | File           | Codeforces Problem | Idea |
  |----------------|---------------------|------|
  | `Bacterial Melee.cpp`    | [759D](https://codeforces.com/contest/759/problem/D) | For every unique subsequence, calculate its total “weight” using combinatorics (number of ways to select positions for letters) |
  | `Equivalent Strings.cpp`     | [559B](https://codeforces.com/problemset/problem/559/B) | The idea is to recursively sort each half and compare the normalized form |
  | `Longest Regular Bracket Sequence.cpp`      | [5C](https://codeforces.com/problemset/problem/5/C) | Given a string with brackets, find the length of the longest valid (well-formed) bracket substring and how many times such a substring occurs |
  | `Palindrome Degree.cpp`    | [7D](https://codeforces.com/problemset/problem/7/D) | Compute total degree of all prefixes using recursive definition. Use rolling hash for palindrome check and DP for efficiency |
  | `Queries for Number of Palindromes.cpp`     | [245H](https://codeforces.com/problemset/problem/245/H) | Given a string and multiple queries [l,r], count how many substrings in that range are palindromes. Preprocess all palindrome substrings for fast query answers |
  | `Two Substrings.cpp`      | [550A](https://codeforces.com/problemset/problem/550/A) | Determine whether the string contains both “AB” and “BA” non-overlapping. Try both orders (AB first, then BA, and vice versa), checking for non-intersection |

---

# Bacterial Melee.cpp

Counts the number of "good" subsequences in a given string, where no character repeats consecutively. Dynamic Programming is used to track valid subsequences of each length ending in a specific character. Combinatorics (nCr) is used to account for permutations across the full string length.

Uses a double DP approach: tracking possible subsequences by length and character, then summing over permutations using precomputed modular inverses for nCr combinations. This design avoids brute-force substring checking.

Techniques Used:
- DP on character sequences
- combinatorics
- modular arithmetic

Interesting Detail: Avoids duplicate character chains using a character-wise DP table.

---

# Equivalent Strings.cpp

Checks whether two strings are "equivalent" under recursive half-swap operations. Uses divide-and-conquer to recursively verify equivalency by comparing both direct and swapped halves.

Techniques Used:
- Recursion
- string slicing
- divide-and-conquer

Interesting Detail: Captures the recursive symmetry concept cleanly using helper boundaries.

---

# Longest Regular Bracket Sequence.cpp

Finds the length and count of the longest valid bracket subsequence. Implements prefix sums and a clever stack-based approach to compute the right match positions. Keeps track of occurrences using auxiliary arrays.

Techniques Used:
- Stack for bracket matching
- prefix sums

Interesting Detail: Uses an auxiliary pos array for quickly identifying matches via bracket depth.

---

# Palindrome Degree.cpp

Calculates the "palindromic degree" of a string — the number of nested palindromes within all prefixes. Uses polynomial rolling hash to compare string segments in O(1) time and builds the result bottom-up.

Techniques Used:
- Polynomial hashing
- dynamic programming

Interesting Detail: Avoids naive substring checks using base-101 hashing and reverse hashing.

---

# Queries for Number of Palindromes.cpp

Preprocesses all palindromic substrings in a string and efficiently answers multiple queries asking how many palindromes exist in a substring. Uses a 2D DP table to cache counts and a separate check table for identifying palindromes.

Combines a palindrome validity table with a prefix-style DP table for fast range query resolution. This dual-table setup allows answering up to 10⁵ queries in optimal time after O(n²) preprocessing.

Techniques Used:
- Palindrome DP
- prefix 2D dynamic programming

Interesting Detail: Uses check[i][j] to mark palindromes and combine counts efficiently.

---

# Two Substrings.cpp

Checks whether "AB" and "BA" occur as non-overlapping substrings in any order within the string. Two passes ensure both orderings are considered independently.

Techniques Used:
- Greedy scanning
- substring matching

Interesting Detail: Handles overlapping edge cases by skipping ahead after a match.

---

# Notes

Bacterial Melee is a classic DP problem enhanced with combinatorial computations and modular arithmetic to efficiently count weighted subsequences.

Equivalent Strings uses a neat recursive approach to test string equivalence under a specific operation, illustrating divide-and-conquer on strings.

Longest Regular Bracket Sequence involves prefix sums and a stack-based method to quickly find longest valid parentheses substrings.

Palindrome Degree utilizes polynomial rolling hash functions to quickly verify palindromes and accumulates their “degree” values with DP.

Queries for Number of Palindromes efficiently answers multiple palindrome count queries using DP preprocessing.

Two Substrings involves simple but careful scanning to detect required non-overlapping patterns in a string.



