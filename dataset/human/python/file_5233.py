import sys
n,m = map(int,input().split())
if m == 1:
    input()
    print('IMPOSSIBLE')
    sys.exit()
mid = [];move = [None]*m
for i in range(m):
    a,b = map(int,input().split())
    move[i] = [a,b]
    if a == 1:mid.append(b)
    if b == 1:mid.append(a)
    if a == n:mid.append(b)
    if b == n:mid.append(a)
check = False
if len(mid) != len(set(mid)):check = True
if check == True:print('POSSIBLE')
else:print('IMPOSSIBLE')
