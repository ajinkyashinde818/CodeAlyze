import sys
readline = sys.stdin.readline

def calc(k):
    return 10-k

S = [0] + list(map(int, readline().strip()))

M = len(S)
inf = 10**9+7
dpn = [inf]*M
dpk = [inf]*M
dpn[0] = 0
dpk[0] = 1
pre = 0
for i in range(1, M):
    s = S[i]
    if s != 9:
        dpn[i] = min(dpn[i-1] + s, dpk[i-1] + calc(s))
        dpk[i] = min(dpn[i-1] + s+1, dpk[i-1] + calc(s+1))
        pre = i
    else:
        dpn[i] = min(dpn[i-1] + s, dpk[pre] + calc(s))
        dpk[i] = dpk[pre]

print(dpn[-1])
