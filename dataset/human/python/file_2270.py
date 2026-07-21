from sys import stdin
D, G = [int(x) for x in stdin.readline().rstrip().split()]
P = []
C = []
for _ in range(D):
    p, c = [int(x) for x in stdin.readline().rstrip().split()]
    P.append(p)
    C.append(c)
ans = 10**9

for i in range(1 << D):
    score = 0
    cnt = 0

    # 全部解く
    for j in range(D):
        if i >> j & 1:
            score += C[j]
            score += P[j]*(j+1)*100
            cnt += P[j]

    # 一部解く(全て解く場合もある)
    for k in range(D-1, -1, -1):
        if i >> k & 1:
            continue
        if score >= G:
            break
        S = (k+1)*100
        for l in range(P[k]+1):
            score += S
            cnt += 1
            if score >= G:
                break
    ans = min(ans, cnt)
print(ans)
