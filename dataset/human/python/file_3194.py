def divideprime(n):
    ret = []
    i = 2
    while i*i <= n:
        cnt = 0
        if(n%i != 0):
            i += 1
            continue
        
        while n % i == 0:
            cnt += 1
            n //= i
        
        ret.append([i,cnt])
        
        i += 1
    
    if n != 1:
        ret.append([n,1])
    
    return ret
    
N = int(input())

divp = divideprime(N)

ans = 0
for t in divp:
    cnt = 0
    e = 0
    s = set([])
    while (t[1]-e > 0) and (t[1]-e not in s):
        ans += 1
        cnt += 1
        e += cnt
        s.add(cnt)

print(ans)
