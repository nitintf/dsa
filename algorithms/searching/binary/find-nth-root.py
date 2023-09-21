def findNthRootOfM(n, m):
    low, high = 0, m

    while low <= high:
        mid = low + (high - low) // 2

        if mid ** n == m:
            return mid

        elif mid ** n < m:
            low = mid + 1
        else:
            high = mid - 1

    return -1


if __name__ == "__main__":
    n = 2
    m = 64

    print(findNthRootOfM(n, m))

    n = 3
    m = 27

    print(findNthRootOfM(n, m))

    n = 4
    m = 86

    print(findNthRootOfM(n, m))
