def solve(bit):
    ret = 0
    score = 0
    done = set()
    for i in range(D):
        if bit[i]:
            done.add(i)
            ret += L[i][0]
            score += ((i + 1) * 100) * L[i][0] + L[i][1]
    j = D - 1
    cnt = 0
    while score < G:
        while j in done:
            j -= 1
        ret += 1
        cnt += 1
        score += (j + 1) * 100
        if cnt == L[j][0]:
            done.add(j)
            score += L[j][1]
            cnt = 0
    return ret

D, G = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(D)]
ans = float('inf')
for i in range(1 << D):
    bit = [0] * D
    for j in range(D):
        if i >> j & 1:
            bit[j] = 1
    ans = min(ans, solve(bit))
print(ans)
