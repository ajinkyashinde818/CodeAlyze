import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


n = I()
a = LI()
a = list(map(lambda x: x - 1, a))
b = LI()
c = LI()

ans = 0
for i in range(n):
    ans += b[a[i]]
    if i > 0 and a[i - 1] + 1 == a[i]:
        ans += c[a[i - 1]]
print(ans)
