import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


n, k, s = LI()
a = []
for _ in range(k):
    a.append(s)
for _ in range(n - k):
    if s == 1:
        a.append(s + 1)
    else:
        a.append(s - 1)
print(*a)
