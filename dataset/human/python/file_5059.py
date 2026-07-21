import sys
(n, m) = list(map(int, input().split()))

ab = []
bn = {}
for i in range(m):
    tmp = list(map(int, input().split()))
    if tmp[0] == 1:
        ab.append(tmp[1])
    elif tmp[1] == n:
        bn[tmp[0]] = 1
for i in ab:
    if i == n:
        print('POSSIBLE')
        sys.exit(0)
    elif i in bn:
        print('POSSIBLE')
        sys.exit(0)

print('IMPOSSIBLE')
