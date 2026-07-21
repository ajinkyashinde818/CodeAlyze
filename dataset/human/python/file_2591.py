D, G = (int(i) for i in input().split())
G = G // 100
P= [0] * D
C= [0] * D

for i in range(D):
    P[i], C[i] = (int(i) for i in input().split())
    C[i] = C[i] // 100

INF = int(1e9)
mem = [[0] * 1010 for _ in range(D+1)] #solve数での最大のスコア
used = [[0] * 1010 for _ in range(D+1)]

def dfs(idx, num):
    if num == 0:
        return 0
    
    if num < 0:
        return -INF

    if idx == D:
        return -INF

    if used[idx][num]:
        return mem[idx][num]
    
    used[idx][num] = 1
    p = P[idx]
    c = C[idx]
    res = -INF
    for i in range(p+1):
        score = (idx + 1) * i;
        if (i == p):
            score = score + c
        nnum = num - i
        res = max(res, score + dfs(idx+1, nnum))
    mem[idx][num] = res;
    return res

ans = INF
for i in range(1001):
    if dfs(0, i) >= G:
        ans = i
        break

print (ans)
