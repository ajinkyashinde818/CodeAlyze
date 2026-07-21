def enum_divisors(n):
    res = []
    a = 2
    while a*a <= n:
        if n % a == 0:
            e = 0
            while n % a == 0:
                e += 1
                n //= a
            res.append((a,e))
        a += 1
    
    if n != 1:
        res.append((n,1))

    return res

n = int(input())
enums = enum_divisors(n)
ans = 0
for i in enums:
    e = i[1]
    j = 0
    while e >= 0:
        j += 1
        e -= j

    ans += j - 1

print(ans)
