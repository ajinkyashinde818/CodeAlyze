import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

k, s = map(int, read().split())
cnt = 0
for x in range(k + 1):
    for y in range(k + 1):
        if 0 <= s - x - y <= k:
            cnt += 1
print(cnt)
