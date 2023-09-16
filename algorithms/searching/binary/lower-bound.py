"""
Binary Search Lower Bound

Algorithm Complexity:
- Time Complexity: O(log n), where n is the size of the array.
- Space Complexity: O(1)

How the Lower Bound is Found:
1. The algorithm initializes two pointers, 'low' and 'high', to the start and end of the array, respectively.
2. It also initializes a variable 'ans' to store the lower bound index, initially set to the length of the array.
3. The algorithm enters a loop while 'low' is less than or equal to 'high'.
4. In each iteration, it calculates the middle index 'mid' as the average of 'low' and 'high'.
5. If the element at 'mid' is greater than or equal to the target, it updates 'ans' to 'mid' and moves 'high' to 'mid - 1' to search for a lower bound in the left half of the array.
6. Otherwise, if the element at 'mid' is less than the target, it moves 'low' to 'mid + 1' to search for a lower bound in the right half of the array.
7. The algorithm continues this process until 'low' becomes greater than 'high'.
8. Finally, it returns the value of 'ans' as the lower bound index.
"""


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


if __name__ == "__main__":
    arr = [1, 2, 3, 5, 6, 7, 8, 9, 10]
    target = 5
    print(bs_lowerBound(arr, target))
    print(bs_lowerBound(arr, 4))
