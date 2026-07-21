import collections
N,M = map(int,input().split())
a = [list(map(int,input().split())) for _ in range(M)]
a.sort()
B = collections.Counter(x[0] for x in a)[1]
C = set([])
for i in range(B):
    C.add(a[i][1])
for i in range(M):
    if a[i][0] in C and a[i][1] == N:
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")
