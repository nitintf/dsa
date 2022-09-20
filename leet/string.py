def numJewelsInStones(jewels: str, stones: str) -> int:
    num = 0
    jewelsL = [x for x in jewels]
    for stn in stones:
        if stn in jewelsL:
            num += 1
    return num


print(numJewelsInStones('aA', 'aAABBBBBBB'))
