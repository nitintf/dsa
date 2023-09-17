"""
162. Find Peek Element 

Clues:
1. No adjacent two numbers are the same
2. the two end of the arrays are -∞
3. You can return any peak.
"""


def findPeekElement(nums):
    if (len(nums) == 1):
        return 0

    # These 2 cheks are for 2nd condition
    if nums[0] > nums[1]:
        return 0

    if nums[len(nums) - 1] > nums[len(nums) - 2]:
        return len(nums) - 1

    low, high = 1, len(nums) - 2

    while low <= high:
        mid = (low + high) // 2

        if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
            return mid
        elif nums[mid] > nums[mid - 1]:
            low = mid + 1
        else:
            high = mid - 1

    return -1


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print(findPeekElement(arr))
    arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    print(findPeekElement(arr))
    arr = [1, 2, 1, 3, 5, 6, 4]
    print(findPeekElement(arr))
