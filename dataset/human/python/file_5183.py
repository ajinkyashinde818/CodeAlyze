import itertools

n,m = map(int,input().split())
ship = []
for _ in range(m):
    a,b = map(int,input().split())
    if a==1:
        ship.append(b)
    if b==n:
        ship.append(a)
ship = sorted(ship)
g = itertools.groupby(ship)
for k,v in g:
    if len(list(v))==2:
        print('POSSIBLE')
        exit()
print('IMPOSSIBLE')
