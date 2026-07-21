import sys
def input():
    return sys.stdin.readline()[:-1]
D,G=map(int, input().split())
G//=100
p=[list(map(int, input().split())) for i in range(D)]
m=[None]*D
for i in range(D):
    m[i]=p[i][0]*(i+1)+p[i][1]//100
l=[None]*2**D
for i in range(2**D):
    l[i]="{:0>{}b}".format(i,D)
a=1000
for i in l:
    c=0
    t=0
    for j in range(D):
        if i[j]=="1":
            t+=m[j]
            c+=p[j][0]
    if t>G:
        if a>c:
            a=c
        continue
    s=i.rfind("0")
    if t+(s+1)*p[s][0]>G:
        c+=(G-t-1)//(s+1)+1
        if a>c:
            a=c
print(a)
