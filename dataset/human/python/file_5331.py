from sys import stdin
n,m=map(int,input().split())
l = [list(map(int, stdin.readline().split())) for _ in range(m)]
s,e=[],[]
for i in l:
    if i[0]==1:
        s.append(i[1])
    if i[1]==n:
        e.append(i[0])
result = list(set(s) & set(e))
print('POSSIBLE' if result else 'IMPOSSIBLE')
