import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

n = int(read())
ans = 0
if n % 2 == 1:
    pass
else:
    cnt = 0
    acc = 5
    while acc <= n:
        cnt += (n // acc) // 2
        acc *= 5
    ans = cnt

print(ans)
