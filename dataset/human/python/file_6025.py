def MAP(): return list(map(int,input().split()))

n = int(input())
a = MAP()
b = MAP()
c = MAP()

ans=b[a[0]-1]
for i in range(1,n):
    ans += b[a[i]-1]
    if a[i-1]+1==a[i]:
        ans+=c[a[i-1]-1]

print(ans)
