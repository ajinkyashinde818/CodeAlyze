import sys
input = sys.stdin.readline
k, n = [int(w) for w in input().split()]
a_li = [int(w) for w in input().split()]

dist = k - a_li[-1] + a_li[0]

for a1, a2 in zip(a_li[:-1], a_li[1:]):
    dist = max(dist, a2-a1)

print(k - dist)
