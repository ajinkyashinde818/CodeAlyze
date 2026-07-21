import bisect

N = int(input())
S = input()
mod = 10 ** 9 + 7

small = []
large = []
for i in range(N * 2):
    if S[i] == 'B':
        if i % 2 == 0:
            small.append(i)
        else:
            large.append(i)
    else:
        if i % 2 == 0:
            large.append(i)
        else:
            small.append(i)

if len(small) != len(large):
    print(0)
else:
    ans = 1
    for i in range(N):
        large_i = large[i]
        smaller = bisect.bisect_left(small, large_i)
        ans = (ans * (smaller - i)) % mod
    for i in range(1, N + 1):
        ans = (ans * i) % mod
    print(ans)
