"""
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

"""

INT32_MIN = -2_147_483_648
INT32_MAX = 2_147_483_647

class Solution:
    def reverse(self, x: int) -> int:
        res = 0
        sign = -1 if x < 0 else 1
        x = abs(x)

        while x != 0:
            digit = x % 10
            x //= 10

            if ( res > (INT32_MAX - digit) // 10):
                return 0

            res = res * 10 + digit

        return res * sign

solution = Solution()
print(solution.reverse(123))
print(solution.reverse(-123))
print(solution.reverse(120))

def reverse_integer(x: int) -> int:
    sign = -1 if x < 0 else 1
    x = str(abs(x))
    x = x[::-1]
    x = int(x)

    if x > INT32_MAX or x < INT32_MIN:
        return 0

    return x * sign

print(reverse_integer(123))
print(reverse_integer(-123))
print(reverse_integer(120))