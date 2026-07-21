import collections
N = int(input())
S = input()

table = collections.defaultdict(int)
for i in range(N):
    table[S[i]] += 1
ans = 1
mod = 10**9 + 7
alpha = 'abcdefghijklmnopqrstuvwxyz'
for x in alpha:
    ans *= table[x] + 1
    ans %= mod

print((ans-1) % mod)
