import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, r = map(int, readline().split())
if 10 < n:
    print(r)
else:
    print(100 * (10 - n) + r)
