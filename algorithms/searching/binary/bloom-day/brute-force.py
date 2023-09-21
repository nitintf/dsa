
def possible(arr, day, m, k):
    n = len(arr)  # size of the array
    cnt = 0
    noOfB = 0
    # count the number of bouquets
    for i in range(n):
        if arr[i] <= day:
            cnt += 1
        else:
            noOfB += cnt // k
            cnt = 0
    noOfB += cnt // k
    return noOfB >= m


def roseGarden(arr, k, m):
    val = m * k
    n = len(arr)  # size of the array
    if val > n:
        return -1  # impossible case
    # find maximum and minimum
    mini = float('inf')
    maxi = float('-inf')
    for i in range(n):
        mini = min(mini, arr[i])
        maxi = max(maxi, arr[i])

    for i in range(mini, maxi+1):
        if possible(arr, i, m, k):
            return i
    return -1


if __name__ == "__main__":
    arr = [1, 10, 3, 10, 2]
    print(roseGarden(arr, 3, 1))

    arr = [7, 7, 7, 7, 12, 7, 7]
    print(roseGarden(arr, 2, 3))
