import sys

n,m = map(int, sys.stdin.readline().split())

mid1 = set()
mid2 = set()
for _ in range(m):
    a,b, = map(int, input().split())
    if a == 1:
        mid1.add(b)
    elif b == n:
        mid2.add(a)
result = bool(mid1 & mid2)
if result:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
