def canBloom(bloomDays, day, m, k):
    counter = 0
    noOfBqs = 0
    for n in bloomDays:
        if n <= day:
            counter += 1
        else:
            noOfBqs += counter // k
            counter = 0

    noOfBqs += counter // k
    return noOfBqs >= m


def minDay(days, m, k):
    low, high = min(days), max(days)

    if m * k > len(days):
        return -1

    while low <= high:
        mid = low + (high - low) // 2

        if canBloom(days, mid, m, k):
            high = mid - 1
        else:
            low = mid + 1

    return low


if __name__ == "__main__":
    arr = [1, 10, 3, 10, 2]
    print(minDay(arr, 3, 1))

    arr = [7, 7, 7, 7, 12, 7, 7]
    print(minDay(arr, 2, 3))
