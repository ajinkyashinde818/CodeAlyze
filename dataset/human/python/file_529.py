if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    bsum = 0
    ma = a[0]
    if ma < 0:
        ma = -ma
    count = 0
    for aa in a:
        if aa < 0:
            count += 1
            aa = -aa
        bsum += aa
        if aa < ma:
            ma = aa
    if count % 2 == 0:
        print(bsum)
    else:
        print(bsum-2*ma)
