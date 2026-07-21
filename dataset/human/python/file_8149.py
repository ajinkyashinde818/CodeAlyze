import sys
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)

K, S = map(int, readline().split())

ans = 0
for X in range(0, K + 1):
    for Y in range(0, K + 1):
        Z = S - X - Y
        if 0 <= Z and Z <= K:
            ans += 1
print(ans)
