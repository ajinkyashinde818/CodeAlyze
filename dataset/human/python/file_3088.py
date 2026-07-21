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
dum = prime_factorize(int(input()))
dum_len = len(dum)

num = 0
ans = 0
cnt = 0
check = 0
for i in range(dum_len):
    if num == dum[i]:
        cnt += 1
        if cnt >= check:
            check += 1
            ans += 1
            cnt = 0
    else:
        num = dum[i]
        ans += 1
        cnt = 0
        check = 2
print(ans)
