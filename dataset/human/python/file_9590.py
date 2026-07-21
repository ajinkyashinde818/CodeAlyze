import sys
readline = sys.stdin.buffer.readline


N, K = map(int, readline().split())
A = list(map(int, readline().split()))
passed = [0] * N
P = []
c = 0
for _ in range(N):
    c = A[c] - 1
    if passed[c] == 1:
        s = c
        break
    P.append(c)
    passed[c] = 1
    
if K <= len(P):
    print(P[K-1] + 1)
else:
    idx = P.index(s)
    m = (K - idx) % (len(P) - idx)

    print(P[idx:][m-1] + 1)
