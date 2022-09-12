# Hackerrank link -> https://www.hackerrank.com/challenges/equal-stacks/problem

a = [1, 2, 1, 1]
b = [1, 1, 2]
c = [1, 1]


def equalStacks(s1, s2, s3):
    sum1, sum2, sum3 = sum(s1), sum(s2), sum(s3)  # 5, 4, 2
    minSum = min(sum1, sum2, sum3)  # 2
    while minSum > 0:
        while sum1 > minSum:
            sum1 -= s1.pop(0)
        while sum2 > minSum:
            sum2 -= s2.pop(0)
        while sum3 > minSum:
            sum3 -= s3.pop(0)
        if sum1 == sum2 and sum2 == sum3:
            break
        minSum = min(sum1, sum2, sum3)
    return minSum


if __name__ == '__main__':
    print(equalStacks(a, b, c))
