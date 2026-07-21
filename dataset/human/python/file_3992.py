n = int(input())
n2 = int(n**0.5//1)

def div(n,p):
    cnt = 0
    a = 1
    while n%p == 0:
        n = n//p
        cnt += 1
        if cnt == a:
            cnt = 0
            a += 1
    return [n,a-1]

ans = 0
for z in range(2,n2):
    if n%z == 0:
        n,cur = div(n,z)
        ans += cur

if n != 1: ans += 1

print(ans)
