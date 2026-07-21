import sys
input = sys.stdin.readline

def inpl(): return list(map(int, input().split()))
D, G = inpl()
P = [0]*D
C = [0]*D
for i in range(D):
    P[i], C[i] = inpl()

ans = sum(P)
for k in range(2**D):
    score = 0
    cnt = 0
    for i in range(D):
        if (k >> i) & 1:
            cnt += P[i]
            score += 100*(i+1)*P[i] + C[i]
    
    for i in range(D-1, -1, -1):
        if (k >> i) & 1 == 0:
            tmp = -(-(G - score)//(100*(i+1)))
            x = max(0, min(P[i]-1, tmp))
            cnt += x
            score += 100*(i+1)*x
    if score >= G:
        ans = min(ans, cnt)
            
print(ans)
