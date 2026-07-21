import sys
input = sys.stdin.readline
N , M = map(int,input().split())
L = []
transit1 = set()
transit2 = set()
for _ in range(M):
    t = tuple(map(int,input().split()))
    L.append(t)
for x in L :
    if x[1] == N:
        transit1.add(x[0])
    if x[0] == 1:
        transit2.add(x[1])
if transit1 & transit2 == set():
    print("IMPOSSIBLE")
else:
    print("POSSIBLE")
