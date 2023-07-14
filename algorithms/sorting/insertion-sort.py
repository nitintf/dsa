def insertionSort(nums):
    n = len(nums)
    # Total number of passees (n - 1)
    for i in range(1, n):
        valueToInsert = nums[i]

        j = i - 1
        while j >= 0 and valueToInsert < nums[j]:
            nums[j + 1] = nums[j]
            j -= 1
        nums[j + 1] = valueToInsert

    return nums


if __name__ == "__main__":
    testCase1 = [3, 5, 1, 4, 7, 8]
    # test case to check adaptive performance
    testCase2 = [1, 2, 3, 4, 5, 6]
    testCase3 = [8, 8, 6, 6, 1, 2]
    testCase4 = [1, 3, 2, 5, 4]

    print(insertionSort(testCase1))
    print(insertionSort(testCase2))
    print(insertionSort(testCase3))
    print(insertionSort(testCase4))
