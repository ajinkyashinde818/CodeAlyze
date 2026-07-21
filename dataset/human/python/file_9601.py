def resolve():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    s = []
    ord = [-1 for i in range(n + 1)]
    rep = 1
    pos = 1
    while ord[pos] == -1:
        ord[pos] = len(s)
        s.append(pos)
        pos = A[pos - 1]
        rep += 1

    rep = len(s) - ord[pos]
    # l: ループが始まる点
    l = ord[pos]
    if k < l:
        print(s[k])
    else:
        # ループが始まるまでずらす
        k -= l
        k %= rep
        print(s[l + k])
resolve()
