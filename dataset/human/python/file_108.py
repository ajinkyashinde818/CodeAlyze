import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

r, g, b, n = map(int, read().split())
cnt = 0
for i in range(n // r + 1):
    for j in range(n // g + 1):
        check = n - (r * i + g * j)
        if check >= 0:
            if check % b == 0:
                cnt += 1
        else:
            break
print(cnt)
