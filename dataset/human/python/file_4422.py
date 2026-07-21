def prime_factorize(n):
    dic = {}
    while n % 2 == 0:
        if 2 in dic:
            dic[2] += 1
        else:
            dic[2] = 1
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            if f in dic:
                dic[f] += 1
            else:
                dic[f] = 1
            n //= f
        else:
            f += 2
    if n != 1:
        if n in dic:
            dic[n] += 1
        else:
            dic[n] = 1
    return dic

n = int(input())

dic = prime_factorize(n)
ans = 0
for value in dic.values():
    left = 1
    right = value
    while left+1 < right:
        mid = (left+right) // 2
        if mid*(mid+1)//2 <= value:
            left = mid
        else:
            right = mid
    ans += left
print(ans)
