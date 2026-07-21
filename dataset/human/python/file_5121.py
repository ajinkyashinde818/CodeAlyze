def abc068_c():
    from collections import Counter
    n, m = map(int, input().split())
    ab = [list(map(int, input().split())) for _ in range(m)]
    candidates = []

    for i in range(m):
        if ab[i][0] == 1:
            candidates.append(ab[i][1])
        elif ab[i][1] == n:
            candidates.append(ab[i][0])

    if max(Counter(candidates).values()) >= 2:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")


abc068_c()
