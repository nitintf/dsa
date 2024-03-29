"""
Binary Search

Time Complexity:
The time complexity of binary search is O(log n), where n is the number of elements in the sorted array.

Description:
Binary search is a search algorithm used to find the position of a target value within a sorted array. It works by repeatedly dividing the search space in half until the target value is found or the search space is empty.
"""


def binarySearch_iterative(arr, target):
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high)//2

        if arr[mid] == target:
            return mid

        if target > arr[mid]:
            low = mid + 1
        elif target < arr[mid]:
            high = mid - 1

    return -1


def binarySearch_recursive(arr, target, low, high):
    if low > high:
        return -1

    mid = (low + high) // 2

    if arr[mid] == target:
        return mid

    if (target > arr[mid]):
        return binarySearch_recursive(arr, target, mid + 1, high)
    else:
        return binarySearch_recursive(arr, target, low, mid - 1)


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    target = 5
    print(binarySearch_iterative(arr, target))
    print(binarySearch_recursive(arr, target, 0, len(arr) - 1))
