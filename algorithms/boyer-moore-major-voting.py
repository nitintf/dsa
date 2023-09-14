def boyerMoore(nums):
    candidate = -1
    votes = 0

    for i in range(len(nums)):
        if votes == 0:
            candidate = nums[i]
            votes = 1
        else:
            if nums[i] == candidate:
                votes += 1
            else:
                votes -= 1

    print(candidate)


if __name__ == "__main__":
    boyerMoore([1, 1, 1, 3, 3, 4, 3, 2, 4, 2])
