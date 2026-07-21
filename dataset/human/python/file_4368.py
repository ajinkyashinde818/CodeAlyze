import sys

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')

def fctr1(n):
    f = list()
    r = int((n+1)**0.5)
    for i in range(2, r+1):
        if n % i == 0:
            c = 0
            while n % i == 0:
                c += 1
                n //= i
            f.append((i, c))
    if n > 1:
        f.append((n, 1))
    return f

n = ni()
l = fctr1(n)
res = 0
for x, c in l:
    t = 1
    while (t + 1) * (t + 2) // 2 <= c:
        t += 1
    res += t
print(res)
