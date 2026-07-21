import sys

stdin = sys.stdin
sys.setrecursionlimit(10 ** 7)

ri = lambda: int(rs())
rl = lambda: list(map(int, stdin.readline().split()))  # applies to only numbers
rs = lambda: stdin.readline().rstrip()  # ignores trailing space

A, B, C = rl()
cookie = min(A+B, C)
C -= cookie
cookie += B
if C > 0:
    cookie += 1

print(cookie)
# 13
