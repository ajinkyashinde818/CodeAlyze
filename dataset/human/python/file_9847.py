from math import log2
n, k = map(int, input().split())
To = []
A = list(map(int, input().split()))
A = list(map(lambda x: x - 1, A))
To.append(A)
for i in range(int(log2(k))):
    N = [0 for i in range(n)]
    for j in range(n):
        N[j] = To[i][To[i][j]]
    To.append(N)

v = 0
for i in reversed(range(int(log2(k)) + 1)):
    l = 1 << i
    if l <= k:
        v = To[i][v]
        k -= l
    else:
        pass

print(v + 1)
