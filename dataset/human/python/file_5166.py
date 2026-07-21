import sys

n, m = list(map(int, input().split()))
mid_set1 = set([])
mid_set2 = set([])

for i in range(m):
    a, b = list(map(int, input().split()))
    if a == 1:
        mid_set1.add(b)
    elif b == n:
        mid_set2.add(a)

if len(mid_set1&mid_set2) > 0:
    print('POSSIBLE')
    sys.exit()
print('IMPOSSIBLE')
