# Manacher’s Algorithm – Linear Time Longest Palindromic Substring

Manacher's algorithm is another efficient approach to find the longest palindromic substring in a string. Here's a breakdown of the algorithm with explanations and examples, avoiding code for clarity:

Intuition:

Instead of building a table like DP, Manacher's algorithm expands palindromes around potential centers and tracks the longest one found. It leverages the fact that a prefix and suffix of a palindrome are also palindromes.
