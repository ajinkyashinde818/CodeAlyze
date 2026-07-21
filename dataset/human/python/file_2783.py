from scipy.sparse.csgraph import floyd_warshall
n,*a=map(int,open(0).read().split())
a,b=a[:n],a[n:]
d=[]
M=max(a)
for k in range(M-1,-1,-1):
    s=set(a)
    e=[[0]*(M+1)for _ in range(M+1)]
    for i in range(M+1):e[i][i]=1
    for i in d+list(range(k,0,-1)):
        t=s.copy()
        for x in s:
            e[x][x%i]=1
            t|={x%i}
        s=t
    c=floyd_warshall(e)
    for x,y in zip(a,b):
        if c[x,y]==float('inf'):
            d+=k+1,
            break
print(-(len(d)==M)or sum(2**k for k in d))
