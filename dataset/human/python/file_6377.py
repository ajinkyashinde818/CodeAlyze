import sys
from fractions import *

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n = ni()
if n % 2 == 1:
    print(0)
else:
    n=n//2
    ans = 0
    while n//5 >0:
        ans += n//5
        n = n // 5
    print(ans)
