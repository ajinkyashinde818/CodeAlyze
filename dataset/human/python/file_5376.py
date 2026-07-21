from collections import defaultdict

N,M=map(int,input().split())
d=defaultdict(set)
for i in range(M):
    a,b=map(int,input().split())
    d[a].add(b)
    d[b].add(a)

for i in d[1]:
    if N in d[i]:
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")
