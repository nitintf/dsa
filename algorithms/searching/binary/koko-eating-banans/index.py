def calculateHours(nums, speed):
    totalHrs = 0
    for num in nums:
        totalHrs += (num + speed - 1) // speed
    return totalHrs


def minEatingSpeed(nums, k):
    low, high = 1, max(nums)

    while low <= high:
        mid = low + (high - low) // 2
        totalHrs = calculateHours(nums, mid)
        print("totalHrs: ", totalHrs, "mid: ",  mid)

        if (totalHrs <= k):
            high = mid - 1
        else:
            low = mid + 1
    return low


if __name__ == "__main__":
    nums = [3, 6, 7, 11]
    k = 8
    print(minEatingSpeed(nums, k))
