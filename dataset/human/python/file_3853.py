import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from collections import Counter


def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n //= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table


n = int(readline())
memo = prime_decomposition(n)
cnt = 0
for v in Counter(memo).values():
    c = 1
    while v > 0:
        if v >= c:
            cnt += 1
            v -= c
        else:
            break
        c += 1
print(cnt)
