from math import factorial

N = int(input())
S = list(input())

MOD = 10 ** 9 + 7

def swap(char):
    if char == 'W':
        return 'B'
    else:
        return 'W'

cnt = 0
for i in range(2 * N):
    if i % 2 == 0:
        S[i] = swap(S[i])
    if S[i] == 'B':
        cnt += 1

if cnt != N or S[0] == 'B' or S[-1] == 'W':
    print(0)
else:
    rest_W = 0
    ans = 1
    for i in range(2 * N):
        if S[i] == 'W':
            rest_W += 1
        if S[i] == 'B':
            ans *= rest_W
            ans %= MOD
            rest_W -= 1
    ans = (ans * factorial(N) % MOD)
    print(ans)
