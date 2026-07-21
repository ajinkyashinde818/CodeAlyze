import sys
l = list(map(int, input().split(' ')))
N = l[0]
N_ = l[0] + 1
M = l[1]
y = []
u = set()

for i in range(M):
    k = list(map(int, input().split()))
    a = k[0]
    b = k[1]
    if (a == 1):
        y.append(b)
    elif (b == N):
        u.add(a)

for i in y:
    if (i in u):
        print('POSSIBLE')
        sys.exit()
print('IMPOSSIBLE')
