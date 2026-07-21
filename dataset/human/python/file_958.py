from math import factorial
N = int(input())
S = list(input())
MOD = 10 ** 9 + 7

X = []
for i, s in enumerate(S):
    if i % 2 == 1:
        X.append(s)
    else:
        if s == 'W':
            X.append('B')
        else:
            X.append('W')


W_cnt = 0
ans = 1
for x in X:
    if x == 'W':
        W_cnt += 1
    else:
        ans *= W_cnt
        ans %= MOD
        W_cnt -= 1
else:
    if W_cnt:
        print(0)
    else:
        print(ans * factorial(N) % MOD)
