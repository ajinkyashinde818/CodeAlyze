import sys
n, m = map(int, input().split())
p = [list(map(int, input().split())) for _ in range(m)]
ln1 = []
ln2 = []
for i in p:
    if i[0] == 1:
        ln1.append(i[1])
for j in p:
    if j[1] == n:
        ln2.append(j[0])

if len(set(ln1) & set(ln2)) == 0:
    print('IMPOSSIBLE')
else:
    print('POSSIBLE')
