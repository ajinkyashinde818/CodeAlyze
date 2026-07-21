import collections

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

def func(a,b):
    cnt = 0
    exp = 1
    borg = b
    while True:
        b = pow(borg, exp)
        if(a%b != 0):
            break
        a = a/b
        exp = exp + 1
        cnt = cnt + 1

    return cnt

input = input()
c = collections.Counter(prime_factorize(int(input)))
L = list(c.values())
K = list(c.keys())
ans = 0
k = 0
for i in range(len(L)):
    k = int(K[i])
    f = func(int(input),k)
    ans = ans + f

print(ans)
