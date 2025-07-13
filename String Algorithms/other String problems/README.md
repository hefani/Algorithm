# Bacterial Melee.cpp

Counts the number of "good" subsequences in a given string, where no character repeats consecutively. Dynamic Programming is used to track valid subsequences of each length ending in a specific character. Combinatorics (nCr) is used to account for permutations across the full string length.

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

