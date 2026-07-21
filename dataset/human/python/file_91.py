def xx(a,b,c):
    ans=0
    if c%a == 0:
        ans += 1
    while c>0:
        if c%b == 0:
            ans+=1
        c -= a
    return ans


r,g,b,n = map(int,input().split())
ans = 0
if n%r==0:
    ans += 1
while n>0:
    ans += xx(g,b,n)
    n -= r
print(ans)
