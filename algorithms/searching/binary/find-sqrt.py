def findSqrt(n):
    low, high = 0, n
    ans = -1

    while low <= high:
        mid = low + (high - low) // 2

        if mid * mid == n:
            return mid

        elif mid * mid < n:
            low = mid + 1
            ans = mid

        else:
            high = mid - 1

    return ans


if __name__ == "__main__":
    n = 28
    print(findSqrt(n))

    n = 10
    print(findSqrt(n))

    n = 36
    print(findSqrt(n))
