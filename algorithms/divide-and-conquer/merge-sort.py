def merge(numsA: list[int], numsB: list[int]) -> list[int]:
    i, j = 0, 0
    numsC = []

    while i <= (len(numsA) - 1) and j <= (len(numsB) - 1):
        if (numsA[i] < numsB[j]):
            numsC.append(numsA[i])
            i += 1
        else:
            numsC.append(numsB[j])
            j += 1

    while i <= (len(numsA) - 1):
        numsC.append(numsA[i])
        i += 1

    while j <= (len(numsB) - 1):
        numsC.append(numsB[j])
        j += 1

    return numsC

def mergeSort(nums: list[int]) -> list[int]:
    if len(nums) <= 1:
        return nums 

    mid = len(nums) // 2
    left = nums[:mid]
    right = nums[mid:]

    leftSorted = mergeSort(left)
    rightSorted = mergeSort(right)

    return merge(leftSorted, rightSorted)

print(mergeSort([5, 8, 2, 1, 6, 7, 4, 3]))

a = 9