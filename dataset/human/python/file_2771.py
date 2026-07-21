from collections import deque
def BFS_dist(n, E, i0=0):
    Q = deque([i0])
    D = [-1] * n
    D[i0] = 0
    while Q:
        x = Q.popleft()
        for c in E[x]:
            if D[c] == -1:
                D[c] = D[x] + 1
                Q.append(c)
    return D

N = int(input())
A = [int(a) for a in input().split()]
B = [int(a) for a in input().split()]

M = 51
X = [[] for _ in range(M)]
for i in range(1, M):
    for j in range(1, i+1):
        X[i].append([i%j, 2**j])

def chk(S):
    M = 51
    X = [[] for _ in range(M)]
    for j in S:
        for i in range(j, M):
            X[i].append(i%j)
    DI = []
    for i in range(M):
        DI.append(BFS_dist(M, X, i))
    for i in range(N):
        if DI[A[i]][B[i]] < 0:
            return 0
    return 1

L1 = [i for i in range(1, 51)]
L2 = []
if chk(L1) == 0:
    print(-1)
else:
    while L1:
        while True:
            if chk(L1 + L2):
                if len(L1) == 0:
                    break
                L1.pop()
            else:
                L2.append(L1[-1]+1 if L1 else 1)
                L1 = [i for i in range(1, L2[-1])]
                break
        if len(L1) == 0:
            break

    print(sum([1<<l for l in L2]))
