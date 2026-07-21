import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

N, R = map(int, readline().split())

ans = R
if (N<10):
    ans += 100*(10-N)
print(ans)
