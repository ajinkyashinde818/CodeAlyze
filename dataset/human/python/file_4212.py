def factor(n):
    res = []
    last = -1
    i = 2
    while i ** 2 <= n:
        while n % i == 0:
            if i != last:
                res.append([i,1])
                last = i
            else:
                res[-1][1] += 1
            n //= i
        i += 1
    if n != 1:
        res.append([n,1])
    return res


n = int(input())

ls = factor(n)
ans=0
for p,cnt in ls:
    i=0
    while 1:
        cnt-=i
        if cnt<(i+1):
            break
        else:
            i+=1
    ans+=i

print(ans)
