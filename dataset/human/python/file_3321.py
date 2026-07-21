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

N = int(input())
A = prime_factorize(N)

if N ==1:
    print(0)
    exit()

cnt = 0
B = []
a,b = 0,0
for i in range(10**3):
    a += 1
    b += a
    B.append(b)

ls = collections.Counter(A)

for k in ls.values():
    i = 0
    while k >= B[i]:
        i +=1
    cnt += i
print(cnt)
