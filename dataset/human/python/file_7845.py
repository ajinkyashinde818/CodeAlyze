import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, k, s = map(int, readline().split())
if s != 1:
    check = s - 1
else:
    check = s + 1
ans = [s] * k + [check] * (n - k)
print(*ans)
