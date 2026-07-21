import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from collections import Counter

N = int(readline())
S = read().rstrip()

MOD = 10 ** 9 + 7

counter = Counter(S)

x = 1
for y in counter.values():
    x *= (y + 1)

x -= 1
answer = x % MOD
print(answer)
