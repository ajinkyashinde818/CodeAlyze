import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


n, m = LI()
a = []
b = []
for _ in range(m):
    ai, bi = LI()
    a.append(ai)
    b.append(bi)

b1 = set(bi for ai, bi in zip(a, b) if ai == 1)
an = set(ai for ai, bi in zip(a, b) if bi == n)

s = b1 & an
ans = 'POSSIBLE' if len(s) > 0 else 'IMPOSSIBLE'
print(ans)
