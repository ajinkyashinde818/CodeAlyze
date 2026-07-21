def factorization(n):
    d = {}
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            d[i] = cnt
    
    if temp!=1:
        d[temp] = 1
    
    if len(d) == 0:
        d[n] = 1
    
    return list(d.values())


def calc(n):
    res = 1
    n -= 1
    while n >= res+1:
        res += 1
        n -= res
    return res

N = int(input())
if N == 1:
    print(0)
    quit()

e = factorization(N)
ans = 0
for ei in e:
    ans += calc(ei)

print(ans)
