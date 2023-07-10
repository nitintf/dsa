def numJewelsInStones(jewels, stones):
    n = 0
    jewelsL = [x for x in jewels]
    for stn in stones:
        if stn in jewelsL:
            n += 1
    return n


print(numJewelsInStones('aA', 'aAABBBBBBB'))
