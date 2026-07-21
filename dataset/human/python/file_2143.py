import sys
import collections

stdin = sys.stdin
 
ri = lambda: int(rs())
rl = lambda: list(map(int, stdin.readline().split()))
rs = lambda: stdin.readline().rstrip()  # ignore trailing spaces

N = ri()
S = list(rs())
MOD = 10 ** 9 + 7
answer = 1
c = collections.Counter(S)
for k, v in c.items():
    answer = (answer * (v + 1)) % MOD

print(answer-1 if answer != 0 else MOD - 1)
