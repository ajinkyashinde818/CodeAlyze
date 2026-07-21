import sys
input = sys.stdin.readline

n,m=map(int,input().split())
a=[]
b=[]
for _ in [0]*m:
    l=list(map(int,input().split()))
    if l[0]==1:a.append(l[1])
    if l[1]==n:b.append(l[0])
print('POSSIBLE' if set(a)&set(b) else 'IMPOSSIBLE')
