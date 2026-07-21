import itertools
D, G = map(int,input().split())
PC = [list(map(int,input().split())) for _ in range(D)]
result = 10**18
for s in itertools.product(range(3), repeat = D):
    s = list(s)
    t = sorted(s, reverse=True)
    idx = 0
    SUM = 0
    ans = 0
    while True:
        if G <= SUM:
            break
        if idx == D:
            ans = 10**18
            break
        if t[idx] == 2:
            SUM += PC[s.index(2)][0] * 100 * (s.index(2)+1) + PC[s.index(2)][1]
            ans += PC[s.index(2)][0]
            s[s.index(2)] = 4
        elif t[idx] == 1:
            if G-SUM >= PC[s.index(1)][0] * 100 * (s.index(1)+1):
                SUM += (PC[s.index(1)][0]-1) * 100 * (s.index(1)+1)
                ans += PC[s.index(1)][0]-1
                s[s.index(1)] == 4
            else:
                if (G-SUM) % (100*(s.index(1)+1)) == 0:
                    ans += (G-SUM) // (100 * (s.index(1)+1))
                    break
                else:
                    ans += ((G-SUM) // (100 * (s.index(1)+1))) + 1
                    break
        idx += 1
    result = min(result, ans)
print(result)
