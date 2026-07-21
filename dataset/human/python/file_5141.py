import sys
input=sys.stdin.readline
n,m=map(int,input().split())
l1=[False]*n
ln=[False]*n
for i in range(m):
    a,b=map(int,input().split())
    if a==1:
        l1[b-1]=True
    if b==1:
        l1[a-1]=True
    if a==n:
        ln[b-1]=True
    if b==n:
        ln[a-1]=True
for i in range(n):
    if l1[i] and ln[i]:
        print('POSSIBLE')
        sys.exit()
print('IMPOSSIBLE')
