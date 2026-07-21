def searchPrime(n):
    i = 2
    p_list = []
    while i * i <= n:
        cnt = 0
        while n % i == 0:
            cnt += 1
            n = n // i
        if cnt != 0:
            p_list.append([i, cnt])
        i += 1
    if n != 1:
        p_list.append([n, 1])
    return p_list

n = int(input())
p_list = searchPrime(n)

ans = 0
for p in p_list:
    i = 1
    while p[1] > 0:
        p[1] = p[1] - i
        if p[1] >= 0:
            ans += 1
        i += 1
print(ans)
