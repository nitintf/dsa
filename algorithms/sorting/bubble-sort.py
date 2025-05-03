import functools
import time


def timer(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        value = func(*args, **kwargs)
        end_time = time.perf_counter()
        run_time = end_time - start_time
        print("Finished in {} secs".format(run_time))
        return value

    return wrapper


@timer
def bubble_sort(nums):
    noOfSwapped = 0
    swapped = False
    # flag to check whether the swapping is happening or not i.e list is already sorted

    for i in range(len(nums) - 1):
        swapped = False
        for j in range(len(nums) - 1 - i):
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
                # print("Swapped :", nums[j], nums[j + 1])
                swapped = True
                noOfSwapped += 1
        if not swapped:
            break

    # print("Total Swapped Elements: ", noOfSwapped)
    return nums


@timer
def recursiveBubbleSort(nums, n):
    # Base case
    if n == 1:
        return nums

    for i in range(n - 1):
        if nums[i] > nums[i + 1]:
            nums[i], nums[i + 1] = nums[i + 1], nums[i]

    return recursiveBubbleSort(nums, n - 1)

if __name__ == '__main__':
    testCase1 = [3, 5, 1, 4, 7, 8]
    # test case to check adaptive performance
    testCase2 = [1, 2, 3, 4, 5, 6]
    testCase3 = [8, 8, 6, 6, 1, 2]
    testCase4 = [1, 3, 2, 5, 4]

    print(bubble_sort(testCase1), len(testCase1))
    # print(bubble_sort(testCase2))
    # print(bubble_sort(testCase3))
    # print(bubble_sort(testCase4))
    # print(recursiveBubbleSort(testCase1, len(testCase1)))
