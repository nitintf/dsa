def findMin(nums):
    low, high = 0, len(nums) - 1
    ans = 99999

    while low <= high:
        mid = low + (high - low) // 2

        # Search space is already sorted
        if nums[low] <= nums[high]:
            ans = min(ans, nums[low])
            break

        if nums[low] <= nums[mid]:
            ans = min(ans, nums[low])
            low = mid + 1
        else:
            ans = min(ans, nums[mid])
            high = mid - 1

    return ans


if __name__ == "__main__":
    arr = [4, 5, 6, 7, 0, 1, 2]
    print(findMin(arr))
