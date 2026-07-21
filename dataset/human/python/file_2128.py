import itertools
N = int(input())
S = input()
mod = 10**9 + 7
count = [1] * 26
for i in range(N):
    count[ord(S[i]) - 97] += 1
print((list(itertools.accumulate(count, lambda x, y: x * y % mod))[-1] - 1) %
      mod)
