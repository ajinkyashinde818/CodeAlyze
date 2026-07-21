import sys
input = sys.stdin.readline
N = int(input())
S = input()[: -1]
table = [S.count(chr(ord("a") + x)) for x in range(26)]
res = 1
mod = 10 ** 9 + 7
for x in range(26):
  res *= table[x] + 1
  res %= mod
print(res - 1)
