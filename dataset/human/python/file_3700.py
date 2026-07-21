import collections

def prime_factorize(n):
    ans = []
    while n % 2 == 0:
        ans.append(2)
        n = n // 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            ans.append(f)
            n = n // f
        else:
            f += 2
    if n != 1:
        ans.append(n)
    
    return ans


n = int(input())

ls = prime_factorize(n)
c = collections.Counter(ls)

if len(c) == 0:
    print(0)
else:
    ans = 0
    for ci in c.values():
        num = 1
        cnt = 1
        while ci >= num:
            ans += 1
            cnt += 1
            num += cnt
    print(ans)
