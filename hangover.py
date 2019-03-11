def comp(n):
    sm = 0
    for x in range(n):
        sm = sm + (1/(x+2))
    return sm

while True:
    val = float(input())
    if val < 0.01:
        break
    minVal = 10000
    lIndex = 1
    rIndex = 1000
    while lIndex < rIndex:
        mid = (lIndex + rIndex)//2
        if comp(mid) > val:
            if comp(mid - 1) > val:
                rIndex = mid
            else:
                lIndex = mid
                break
        elif comp(mid) < val:
            lIndex = mid + 1
        else:
            lIndex = mid
            break
    print("{0} card(s)".format(lIndex))
