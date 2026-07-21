N, K = map(int, input().split())
ai = list(map(int, input().split()))
for i in range(N):
    ai[i] -= 1
    
import math
dv = []
dv.append(ai)
for k in range(1, int(math.log2(K)) + 1):
    l = [0] * N
    dv.append(l)
    for n in range(N):
        dv[k][n] = dv[k - 1][dv[k - 1][n]]
        
#a = []
now = 0
for i in range(int(math.log2(K)) + 1):
    if K >> i & 1:
        #a.append(i)
        now = dv[i][now]
print(now + 1)
