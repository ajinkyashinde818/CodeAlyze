import sys
n,m=map(int,input().split())

a=[]
b=[]
l1=[False for i in range(n)]
ln=[False for i in range(n)]

for i in range(m):
    c=[int(i) for i in input().split()]
    a.append(c[0])
    b.append(c[1])
    if c[0]==1 or c[1]==1:
        l1[c[0]*c[1]]=True
    if c[0]==n or c[1]==n:
        ln[c[0]*c[1]//n]=True

for i in range(n):
    if l1[i] and ln[i]:
        print("POSSIBLE")
        sys.exit()

print("IMPOSSIBLE")
