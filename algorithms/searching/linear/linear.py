import sys


def linearSearch_idx(nums, target):
    if len(nums) == 0:
        return -1

    for i in range(0, len(nums)):
        if nums[i] == target:
            return i

    return -1


def linearSearch_bool(nums, target):
    if len(nums) == 0:
        return False

    for n in nums:
        if n == target:
            return True

    return False


def linearSearch_int(nums, target):
    if len(nums) == 0:
        return -1

    for i in range(0, len(nums)):
        if nums[i] == target:
            return nums[i]

    return sys.maxsize


if __name__ == "__main__":
    nums = [3, 8, 2, 6, 4, 0, 34, 56]

    print(linearSearch_idx(nums, 6))
    print(linearSearch_bool(nums, 6))
    print(linearSearch_int(nums, 6))

    print(linearSearch_idx(nums, 16))
    print(linearSearch_bool(nums, 16))
    print(linearSearch_int(nums, 16))
