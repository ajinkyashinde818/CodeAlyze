import sys

stdin = sys.stdin
ns = lambda: stdin.readline().rstrip()
na = lambda: list(map(int, stdin.readline().split()))
ni = lambda: int(ns())

n = ni()

if n % 2 == 1:
    print(0)
    exit()

n //= 2
cnt = 0
while n > 0:
    cnt += n // 5
    n //= 5
print(cnt)
