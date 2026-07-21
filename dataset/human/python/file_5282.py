import sys
input = sys.stdin.readline

n, m = map(int, input().split())

transit = []
transit_ = []

for a,b in (map(int, input().split()) for _ in range(m)):
    if a == 1:
        transit.append(b)
    if b == n:
        transit_.append(a)

if set(transit)&set(transit_):
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
