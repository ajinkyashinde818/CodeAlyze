from collections import defaultdict

N, K = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]

d = defaultdict(lambda: -1)
d[1] = 0
L = [1]
i = 0
k = i
while i<N:
    if d[A[k]]==-1:
        d[A[k]] = i+1
        L.append(A[k])
        k = A[k]-1
    else:
        p = d[A[k]]
        q = i+1
        break
    i += 1

try:
    print(L[K])
except:
    L = L[p:]
    print(L[(K-p)%(q-p)])
