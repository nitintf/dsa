def partition(nums, start_idx, end_idx):
    pivot = nums[end_idx]
    left_idx, right_idx = start_idx, end_idx - 1

    while left_idx <= right_idx:

        # walk until we find something on the left side that belongs
        # on the right (less than the pivot)
        while left_idx <= end_idx and nums[left_idx] < pivot:
            left_idx += 1

        # Walk until we find something on the right side that belongs
        # on the left (greater than the pivot)
        while right_idx >= start_idx and nums[right_idx] >= pivot:
            right_idx -= 1

        if left_idx < right_idx:
            nums[right_idx], nums[left_idx] = nums[left_idx], nums[right_idx]
        else:
            nums[end_idx], nums[left_idx] = nums[left_idx], nums[end_idx]

    return left_idx


def quicksort(nums, start_idx, end_idx):
    if start_idx >= end_idx:
        return

    # Divide the list into 2 smaller halves
    pivot_idx = partition(nums, start_idx, end_idx)

    # recursively sort each sublist
    quicksort(nums, start_idx, pivot_idx - 1)
    quicksort(nums, pivot_idx + 1, end_idx)


if __name__ == '__main__':
    testCase1 = [3, 5, 1, 4, 7, 8]
    testCase2 = [3]

    quicksort(testCase1, 0, len(testCase1) - 1)

    print(testCase1)
