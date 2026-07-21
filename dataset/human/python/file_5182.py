import sys

input = sys.stdin.readline
n, m = map(int, input().split())
ab = {}

for _ in range(m):
    a, b = map(int, input().split())
    if a not in ab:
        ab[a] = [b]
    else:
        ab[a].append(b)
ans = 0
for i in ab[1]:
    if i in ab:
        if n in ab[i]:
            ans = 1
        else:
            continue
    else:
        continue

if ans == 1:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
