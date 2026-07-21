def f(n):
    res = 0
    s = 0
    for i in range(1,n+1):
        s += i
        if s <=n:
            res = i
        else:
            break
    return res
n = int(input())
p =2
ans = 0
while p*p <= n:
    e = 0
    while n%p == 0:
        e += 1
        n//=p
    ans += f(e)
    p +=1
if n >1:
    ans += 1
print(ans)
