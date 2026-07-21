from collections import defaultdict

X, Y = map(str, input().split())

d = defaultdict(int)
i = 0
for s in 'ABCDEF':
    d[s] = i
    i += 1

if d[X] < d[Y]:
    print('<')
elif d[X] > d[Y]:
    print('>')
else:
    print('=')
