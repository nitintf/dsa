def findKRotation(arr):
    low, high = 0, len(arr) - 1
    ans = 9999
    idx = 0

    while low <= high:
        mid = low + (high - low) // 2

        # Search space is already sorted
        if arr[low] <= arr[high]:
            if arr[low] < ans:
                idx = low
                ans = arr[low]
            break

        if arr[low] <= arr[mid]:
            if arr[low] < ans:
                idx = low
                ans = arr[low]
            low = mid + 1
        else:
            if arr[mid] < ans:
                idx = mid
                ans = arr[mid]
            high = mid - 1

    return idx


if __name__ == "__main__":
    arr = [10, 15, 1, 3, 8]
    print(findKRotation(arr))

    arr = [3, 4, 5, 1, 2]
    print(findKRotation(arr))

    arr = [4, 5, 6, 7, 0, 1, 2]
    print(findKRotation(arr))
