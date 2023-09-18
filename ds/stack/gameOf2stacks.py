# Problem - https://www.hackerrank.com/challenges/game-of-two-stacks/problem?isFullScreen=true

def twoStacks(maxSum, a, b):
    a_attempts = b_attempts = 0
    a_sum = b_sum = 0
    nums = []

    while a_sum < maxSum:
        if len(a) == 0:
            break
        else:
            num = a.pop(0)
            if (a_sum + num) >= maxSum:
                break
            else:
                nums.append(num)
                a_sum += num
                a_attempts += 1

    while (a_sum + b_sum) < maxSum:
        if len(b) == 0:
            break
        else:
            num = b.pop(0)
            if ((a_sum + b_sum) + num) >= maxSum:
                break
            else:
                nums.append(num)
                b_sum += num
                b_attempts += 1

    return a_attempts + b_attempts


if __name__ == '__main__':
    A = [16, 0, 16, 5, 0, 16, 12, 1, 12, 14, 19, 15, 13, 0, 10, 14, 15,
         14, 13, 12, 12, 15, 4, 15, 14, 8, 16, 16, 14, 0, 16, 2, 0, 12, 7]
    B = [0, 0, 19, 13, 5, 13, 4, 0, 7, 5, 2, 13, 12, 8, 6, 4,
         13, 13, 0, 8, 7, 0, 16, 15, 14, 8, 11, 16, 8, 15, 3, 0]
    maxSum = 29
    att = twoStacks(maxSum, A, B)
    print(att)
