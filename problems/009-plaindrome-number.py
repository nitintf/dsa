class Solution:
    def isPalindrome(self, x: int) -> bool:
        res = 0
        y = abs(x)

        while y != 0:
            digit = y % 10
            y //= 10

            res = res * 10 + digit
        
        return res == x

    def isPalindrome2(self, x: int) -> bool:
        y = str(abs(x))[::-1]
        return x == int(y)


