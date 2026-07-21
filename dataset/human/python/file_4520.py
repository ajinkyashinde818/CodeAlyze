def main(n):

    prime = []
    if n < 2:
        prime.append((1,0))
    for p in range(2,int(n**0.5)):
        cnt = 0
        if p*p > n:
            break
        while n%p == 0:
            n //= p
            cnt += 1
        prime.append((p,cnt))
    if n > 1:
        prime.append((n,1))
    return prime
                    
n = int(input())    
pf = main(n)

ans = 0
for p, f in pf:
    cnt = 1
    while f >= cnt:
        f -= cnt
        ans += 1
        cnt += 1

print(ans)
