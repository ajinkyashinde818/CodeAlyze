k,n=map(int,input().split())
a=list(map(int,input().split()))
a=a*2
s=0
t=10**9
def dis(a,b,k):
    if b-a<0:
        return b-a+k
    else:
        return b-a
for i in range(n):
    s=min(k-dis(a[i],a[i+1],k),k-dis(a[i-1+n],a[i],k))
    t=min(s,t)
print(t)
