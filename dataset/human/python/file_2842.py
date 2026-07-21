import collections

p = int(input())


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

l = prime_factorize(p)
sl = set(l)
lsl = list(set(l))
c = collections.Counter(l)
ans = 0
#print(c)
#print(lsl)
for i in range(len(lsl)):
    cnt = 0
    #print(c[lsl[i]])
    #print(i)
    if c[lsl[i]] == 1:
        ans += 1
    else:
        for j in range(1, c[lsl[i]]):
            cnt += j

            #print(c[lsl[i]])
            if cnt <= c[lsl[i]]:
                ans += 1
print(ans)
