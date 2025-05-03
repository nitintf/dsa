def selectionSort(nums):
    # We can either find the smallest el and sort it at first position of unsorted array at right side or we can find lragest el and sort it at last position of unsorted array at left side
    n = len(nums)

    for i in range(n):
        smallest_idx = i
        for j in range(i + 1, n):
            if nums[j] < nums[smallest_idx]:
                smallest_idx = j
        nums[i], nums[smallest_idx] = nums[smallest_idx], nums[i]

    return nums

testCase1 = [3, 5, 1, 4, 7, 8]
# test case to check adaptive performance
testCase2 = [1, 2, 3, 4, 5, 6]
testCase3 = [8, 8, 6, 6, 1, 2]
testCase4 = [1, 3, 2, 5, 4]

print(selectionSort(testCase1))
print(selectionSort(testCase2))
print(selectionSort(testCase3))
print(selectionSort(testCase4))
