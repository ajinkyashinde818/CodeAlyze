from collections import Counter
n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = Counter(A)
D = Counter(B)
for k, v in C.items():
    if v + D[k] > n:
        print("No")
        exit()
print("Yes")
seen = set()
L = []
E = dict()
for i, a in enumerate(A):
    if a not in seen:
        seen.add(a)
        if i != 0:
            E[A[i-1]] = i-1
E[A[-1]] = -1
seen = [False]*n
K = [-1]*n
M = []
for k, v in D.items():
    if k in C:
        M.append((C[k]+v, k))
M.sort(reverse=True)
for p, q in M:
    if q in D:
        s = D[q]
        i = E[q]
        for j in range(s):
            if seen[(i+j+1)%n]:
                break
            seen[(i+j+1)%n] = True
            K[(i+j+1)%n] = q
            D[q] -= 1
        else:
            D.pop(q)
            
            
for i in range(n-1, -1, -1):
    if K[i] == -1:
        for k in D.keys():
            if A[i] != k:
                K[i] = k
                break
        D[k] -= 1
        if D[k] == 0:
            D.pop(k)
print(*K)
