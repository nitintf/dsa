def bs_lowerBound(arr, target):
    low, high = 0, len(arr) - 1
    ans = len(arr)

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] >= target:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    return ans


def bs_upperBound(arr, target):
    low, high = 0, len(arr) - 1
    ans = len(arr)

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] > target:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    return ans


def firstAndLastOccurence(nums, target):
    lb = bs_lowerBound(nums, target)
    if lb == len(nums) or nums[lb] != target:
        return [-1, -1]
    return [lb, bs_upperBound(nums, target) - 1]


if __name__ == "__main__":
    arr = [1, 2, 3, 5, 6, 7, 8, 8, 9, 10]
    target = 5
    print(firstAndLastOccurence(arr, target))
    print(firstAndLastOccurence(arr, 4))
    print(firstAndLastOccurence(arr, 8))
