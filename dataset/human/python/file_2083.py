import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from collections import Counter

n = int(readline())
s = list(readline().rstrip().decode())
ans = 1
mod = 10 ** 9 + 7
for v in Counter(s).values():
    ans *= v + 1
    ans %= mod
print((ans - 1) % mod)
