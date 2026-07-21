N,K = map(int,input().split())
A = list(map(int,input().split()))
A = [0] + A
c = {}
c[1] = 0
n = 0
k = 1
while c.get(A[k]) is None or c[A[k]] != 2:
    if c.get(A[k]) is None:
        c[A[k]] = 0
    else:
        c[A[k]] += 1
    n += 1
    k = A[k]

from collections import Counter
if n <= K:
    num = Counter(c.values())[2]
    sa = len(c)-num
    bbb = K - sa
    m = bbb % num
    abc = list(c.keys())
    abc = abc[sa:len(c)]
    print(abc[m])
else:
    a = 1
    for i in range(K):
        a = A[a]
    print(a)
