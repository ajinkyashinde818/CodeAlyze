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
ans = float('inf')
sums = [a[0]]
for i in range(1, n):
    sums.append(sums[-1] + a[i])

for i in range(n - 1):
    x = sums[i]
    y = sums[-1] - sums[i]
    # print(f'{x=}, {y=}')
    ans = min(ans, abs(x - y))
print(ans)
