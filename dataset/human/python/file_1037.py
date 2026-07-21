from sys import stdin

N = int(stdin.readline().rstrip())
S = stdin.readline().rstrip()

ans = 1
inf = 10 ** 9 + 7
d = 'L'
l_count = 1
r_count = 0

if S[0] == 'W' or S[2 * N - 1] == 'W':
    print(0)
    exit()

for i in range(1, 2 * N):
    if S[i] != S[i - 1]:
        if d == 'R':
            ans *= l_count - r_count
            ans %= inf
            r_count += 1
        else:
            l_count += 1
    else:
        if d == 'R':
            d = 'L'
            l_count += 1
        else:
            ans *= l_count - r_count
            ans %= inf
            d = 'R'
            r_count += 1

if l_count != r_count:
    print(0)
    exit()

for j in range(1, N + 1):
    ans *= j
    ans %= inf

print(ans % inf)
