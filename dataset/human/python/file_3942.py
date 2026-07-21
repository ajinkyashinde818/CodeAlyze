def pf(n):
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

def f(x):
    N = 2
    while 1:
        A = N * (N + 1) / 2
        if x < A:
            return N - 1
        N += 1

N = int(input())

div = pf(N)
exp = []

begin =-1
for i in range(len(div)):
    A = div[i]

    if i == len(div) - 1:
        exp.append(i - begin)
        break

    if div[i + 1] != A:
        exp.append(i - begin)
        begin = i

ans = 0

for i in exp:
    ans += f(i)

print(ans)
