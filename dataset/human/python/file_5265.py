import sys
input = sys.stdin.readline

N, M = map(int, input().split())
L = [[int(v) for v in input().split()] for _ in range(M)]
m = [set() for _ in range(N)]

for l, r in L:
    l -= 1
    r -= 1
    
    m[l].add(r)
    
N -= 1
for v in m[0]:
    if N in m[v]:
        print("POSSIBLE")
        exit()
        
print("IMPOSSIBLE")
