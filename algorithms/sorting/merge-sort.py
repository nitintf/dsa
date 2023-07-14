def merge(a,  b):
    i, j = 0, 0
    c = []

    while i <= (len(a) - 1) and j <= (len(b) - 1):
        if a[i] < b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1

    while i <= (len(a) - 1):
        c.append(a[i])
        i += 1

    while j <= (len(b) - 1):
        c.append(b[j])
        j += 1

    return c


def mergeSort(nums):

    # Base case: single element list
    if len(nums) <= 1:
        return nums

    # Split the input in half
    mid_idx = len(nums) // 2
    left = nums[:mid_idx]
    right = nums[mid_idx:]

    left_sorted = mergeSort(left)
    right_sorted = mergeSort(right)

    return merge(left_sorted, right_sorted)


if __name__ == "__main__":
    testCase1 = [3, 5, 1, 4, 7, 8]
    # test case to check adaptive performance
    testCase2 = [1, 2, 3, 4, 5, 6]
    testCase3 = [8, 8, 6, 6, 1, 2]
    testCase4 = [1, 3, 2, 5, 4]

    print(mergeSort(testCase1))
    print(mergeSort(testCase2))
    print(mergeSort(testCase3))
    print(mergeSort(testCase4))

    # # test case for merging
    # arr1 = [1, 4, 5]
    # arr2 = [2, 3, 6]

    # print(merge(arr1, arr2))
