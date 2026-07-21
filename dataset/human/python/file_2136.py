import sys
from string import ascii_lowercase
stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

N = read_int()[0]
S = read_str()

res = 1
count = [0 for _ in range(26)]
alpha = ascii_lowercase

for i in range(N):
    st = alpha.find(S[i])
    count[st] += 1
    if count[st] > 1:
        res += res // count[st]
    else:
        res *= 2
res -= 1
big = 10**9 + 7
print(res % big)
