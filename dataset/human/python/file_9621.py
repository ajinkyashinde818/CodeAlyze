import sys
sys.setrecursionlimit(10**6)
def f(x,dic,i):
    p=dic1[x]
    if p in dic:
        return [dic,p]
    else:
        dic[p]=i
        return f(p,dic,i+1)

def inv(x,dic):
    for k,v in dic.items():
        if v==x:
            return k

n,k=map(int,input().split())
m=[i for i in range(n)]
l=list(map(int,input().split()))
for i in range(n):
    l[i]-=1
dic1=dict(zip(m,l))
d={0:0}
trace1=f(0,d,1)
u=trace1[0]
i=len(u)
if k<i:
    print(inv(k,u)+1)
else:
    d={trace1[1]:0}
    trace2=f(trace1[1],d,1)
    v=trace2[0]
    j=len(v)
    k=k-i
    k=k%j
    print(inv(k,v)+1)
