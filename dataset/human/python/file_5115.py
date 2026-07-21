def resolve():
    N, M = list(map(int, input().split()))
    AB = [list(map(int, input().split())) for i in range(M)]
    d = {}
    for ab in AB:
        if ab[0] not in d:
            d[ab[0]] = [ab[1]]
        else:
            d[ab[0]].append(ab[1])
    if 1 not in d:
        print("IMPOSSIBLE")
        return
    for i in d[1]:
        if i not in d:
            continue
        if N in d[i]:
            print("POSSIBLE")
            return
    print("IMPOSSIBLE")



if '__main__' == __name__:
    resolve()
