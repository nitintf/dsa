import math


def isSumSmallerOrEqual(nums, divisor, threshold):
    numsSum = 0
    for num in nums:
        numsSum += math.ceil(num / divisor)

    return numsSum <= threshold


def smallestDivisor(nums, threshold):
    low, high = 1, max(nums)
    ans = len(nums)

    while low <= high:
        mid = low + (high - low) // 2

        if isSumSmallerOrEqual(nums, mid, threshold):
            high = mid - 1
        else:
            low = mid + 1

    return low


if __name__ == "__main__":
    nums = [1, 2, 5, 9]
    threshold = 6
    print(smallestDivisor(nums, threshold))
