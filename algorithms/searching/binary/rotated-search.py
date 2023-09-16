def findPivot(nums):
    low, high = 0, len(nums) - 1

    while low <= high:
        mid = (low + high) // 2

        if nums[mid] > nums[high]:
            low = mid + 1
        else:
            high = mid - 1

    return low


def binarySearch(nums, low, high, target):
    while low <= high:
        mid = (low + high) // 2

        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def searchInSortedRotatedArrayWithPivot(nums, target):
    # First find the pivot point
    pivot = findPivot(nums)

    # If we didn't find a pivot, then the array is not rotated
    if pivot == -1:
        return binarySearch(nums, 0, len(nums) - 1, target)

    # If we found a pivot, then first compare with the target and then search in two subarrays accordingly
    if nums[pivot] == target:
        return pivot
    if nums[0] <= target:
        return binarySearch(nums, 0, pivot - 1, target)
    return binarySearch(nums, pivot + 1, len(nums) - 1, target)


def searchInSortedRotatedArray(nums, target):
    low, high = 0, len(nums) - 1

    while low <= high:
        mid = (low + high) // 2

        if nums[mid] == target:
            return mid

        if nums[low] <= nums[mid]:
            if nums[low] <= target and target <= nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        else:
            if nums[mid] <= target and target <= nums[high]:
                low = mid + 1
            else:
                high = mid - 1

    return -1


if __name__ == "__main__":
    arr = [4, 5, 6, 7, 0, 1, 2]
    target = 0
    print(searchInSortedRotatedArray(arr, target))
    print(searchInSortedRotatedArrayWithPivot(arr, target))

    arr = [4, 5, 6, 7, 0, 1, 2]
    target = 3
    print(searchInSortedRotatedArray(arr, target))
    print(searchInSortedRotatedArrayWithPivot(arr, target))

    arr = [1]
    target = 0
    print(searchInSortedRotatedArray(arr, target))
    print(searchInSortedRotatedArrayWithPivot(arr, target))

    arr = [1, 3]
    target = 3
    print(searchInSortedRotatedArray(arr, target))
    print(searchInSortedRotatedArrayWithPivot(arr, target))

    arr = [3, 1]
    target = 3
    print(searchInSortedRotatedArray(arr, target))
    print(searchInSortedRotatedArrayWithPivot(arr, target))

    arr = [3, 1]
    target = 1
    print(searchInSortedRotatedArray(arr, target))
    print(searchInSortedRotatedArrayWithPivot(arr, target))

    arr = [3, 1]
    target = 0
    print(searchInSortedRotatedArray(arr, target))
