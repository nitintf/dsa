"""
Binary Search Lower Bound

Algorithm Complexity:
- Time Complexity: O(log n), where n is the size of the array.
- Space Complexity: O(1)

How the Upper Bound is Found:
1. Initialize two pointers, 'low' and 'high', to the start and end of the array, respectively.
2. Initialize a variable 'ans' to store the higher bound index, initially set to length of array.
3. Enter a loop while 'low' is less than or equal to 'high'.
4. In each iteration, calculate the middle index 'mid' as the average of 'low' and 'high'.
5. If the element at 'mid' is greater than the target, update 'ans' to 'mid' and move 'high' to 'mid - 1' to search for a higher bound in the left half of the array.
6. Otherwise, if the element at 'mid' is less than or equal to the target, move 'low' to 'mid + 1' to search for a higher bound in the right half of the array.
7. Continue this process until 'low' becomes greater than 'high'.
8. Finally, return the value of 'ans' as the higher bound index.
"""


def bs_upperBound(arr, target):
    low, high = 0, len(arr) - 1
    ans = len(arr)

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] > target:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    return ans


if __name__ == "__main__":
    arr = [1, 2, 3, 5, 6, 7, 8, 9, 10]
    target = 5
    print(bs_upperBound(arr, target))
    print(bs_upperBound(arr, 4))
