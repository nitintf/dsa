def print1ToN(n):
    name = "Nitin"
    if (n == 0):
        return
    print(name)
    print1ToN(n-1)


# print1ToN(5)


def sumOfFirstN(n, sum):
    if n < 1:
        print(sum)
        return
    sumOfFirstN(n - 1, sum + n)


# sumOfFirstN(5, 0)


ar = [1, 2, 3, 4, 5]
# print(ar[::-1])


def revArrayIterative1(arr):
    newArr = []
    for i in range(len(arr), 0):
        print(i)
        newArr.append(arr[i])
    print(newArr)


revArrayIterative1(ar)
