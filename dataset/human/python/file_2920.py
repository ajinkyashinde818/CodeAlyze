import collections

N = int(input())

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

c = collections.Counter(prime_factorize(N))

ans=0
for i in c.values():
    tmp = i
    cnt=0
    val=1
    while True:
        tmp = tmp-val
        val+=1

        if tmp > 0:
            cnt+=1
        
        if tmp == 0:
            cnt+=1
            ans+=cnt
            break
        
        if tmp < 0:
            ans+=cnt
            break

print(ans)
