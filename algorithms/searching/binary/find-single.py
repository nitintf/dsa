def isOddIndex(num):
    return num % 2 != 0


def singleNonDuplicate(nums):
    if len(nums) == 1:
        return nums[0]

    if nums[0] != nums[1]:
        return nums[0]

    if nums[len(nums) - 1] != nums[len(nums) - 2]:
        return nums[len(nums) - 1]

    low, high = 1, len(nums) - 2

    while low <= high:
        mid = low + (high - low) // 2

        if nums[mid - 1] != nums[mid] and nums[mid + 1] != nums[mid]:
            return nums[mid]

        if nums[mid - 1] == nums[mid] and isOddIndex(mid) or nums[mid + 1] == nums[mid] and not isOddIndex(mid):
            low = mid + 1
        else:
            high = mid - 1


if __name__ == "__main__":
    arr = [1, 1, 2, 3, 3, 4, 4, 8, 8]
    print(singleNonDuplicate(arr))

    arr = [3, 3, 7, 7, 10, 11, 11]
    print(singleNonDuplicate(arr))

    arr = [1, 1, 2, 2, 3, 3]
    print(singleNonDuplicate(arr))

    arr = [1, 1, 2, 2, 3, 3, 4, 4]
    print(singleNonDuplicate(arr))

    arr = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6]
    print(singleNonDuplicate(arr))

    arr = [1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6]
    print(singleNonDuplicate(arr))

    arr = [1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7]
    print(singleNonDuplicate(arr))
