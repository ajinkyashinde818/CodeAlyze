import sys

int1 = lambda x: int(x) - 1
readline = sys.stdin.readline
readlines = sys.stdin.readlines
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int1, readline().split()))
prn = lambda x: print(*x, sep='\n')

n, k = nm()
m = 64
a = nl()
table = list()
table.append(a)
for _ in range(m-1):
    f = table[-1]
    g = [f[f[i]] for i in range(n)]
    table.append(g)
crt = 0
for i in range(m):
    if k & 1:
        crt = table[i][crt]
    k >>= 1
print(crt + 1)
