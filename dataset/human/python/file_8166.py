from math import factorial
import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


k, s = LI()
ans = 0
for x in range(k + 1):
    for y in range(k + 1):
        z = s - (x + y)
        if 0 <= z <= k:
            ans += 1
print(ans)
