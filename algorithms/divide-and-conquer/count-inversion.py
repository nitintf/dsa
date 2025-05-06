# -----------------------------------------------------------------------------
# Algorithm to count inversions in an array using Divide and Conquer (Modified Merge Sort)
#
# An inversion in an array is a pair of elements (i, j) such that i < j and
# arr[i] > arr[j]. The total number of inversions is a measure of how far the
# array is from being sorted.
#
# This implementation uses a divide and conquer approach, similar to merge sort:
#   1. The array is recursively divided into two halves.
#   2. The number of inversions is counted in each half.
#   3. During the merge step, the number of "split inversions" (where one element
#      is in the left half and the other is in the right half) is counted.
#   4. The total inversion count is the sum of inversions in the left half,
#      right half, and split inversions.
#
# Time Complexity: O(n log n)
# -----------------------------------------------------------------------------

def countSplitInversion(numsA: list[int], numsB: list[int]) -> tuple[int, list[int]]:
    i, j = 0, 0
    numsC = []

    splitInversionCount = 0

    while i < len(numsA) and j < len(numsB):
        if numsA[i] <= numsB[j]:
            numsC.append(numsA[i])
            i += 1
        else:
            numsC.append(numsB[j])
            splitInversionCount += len(numsA) - i
            j += 1

    if i < len(numsA):
        numsC.extend(numsA[i:])

    if j < len(numsB):
        numsC.extend(numsB[j:])

    return splitInversionCount, numsC

def countInversion(nums: list[int]) -> tuple[int, list[int]]:

    if len(nums) <= 1:
        return 0, nums 

    mid = len(nums) // 2
    left = nums[:mid]
    right = nums[mid:]

    leftInversionCount, leftNums = countInversion(left)
    rightInversionCount, rightNums = countInversion(right)

    splitInversionCount, sortedNums = countSplitInversion(leftNums, rightNums)

    return leftInversionCount + rightInversionCount + splitInversionCount, sortedNums

def numberOfInversions(nums):
    count, _ = countInversion(nums)
    return count


if __name__ == "__main__":
    arr1 = [1, 2, 3, 4, 5]
    arr2 = [5, 4, 3, 2, 1]
    arr3 = [2, 4, 1, 3, 5]
    arr4 = [1, 3, 2, 3, 1]
    arr6 = [1]
    arr7 = []

    print(countInversion(arr1))
    print(countInversion(arr2))
    print(countInversion(arr3))
    print(countInversion(arr4))
    print(countInversion(arr6))
    print(countInversion(arr7))