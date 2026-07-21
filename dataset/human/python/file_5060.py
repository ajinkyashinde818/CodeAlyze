import sys
input = sys.stdin.readline
n,m=map(int,input().split())
ab=[[int(i) for i in input().split()] for j in range(m)]

li=[[] for i in range(n+1)]

for a,b in ab:
    li[a].append(b)

li2=[]
for i in li[1]:
    li2.append(i)

ans=False
for i in li2:
    if n in li[i]:
        ans=True
print('POSSIBLE' if ans else 'IMPOSSIBLE')
