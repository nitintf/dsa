import math


def canDistribute(quan, mid, n):
    return sum(math.ceil(q/mid) for q in quan) > n


class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        low, high = 1, max(quantities)

        while low <= high:
            mid = low + (high - low) // 2
            if (canDistribute(quantities, mid, n)):
                low = mid + 1
            else:
                high = mid - 1

        return low
