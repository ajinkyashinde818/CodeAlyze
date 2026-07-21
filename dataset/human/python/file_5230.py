import sys
n,m = map(int,input().split())
ls = [list(map(int,input().split())) for _ in range(m)]
di = []
new = []
for i in range(m):
    if ls[i][0] == 1:
        di.append(ls[i][1])
    if ls[i][1] == n:
        new.append(ls[i][0])
f = list(set(di) & set(new))
if len(f) > 0:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
