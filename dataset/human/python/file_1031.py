import sys
from collections import Counter
from math import factorial

N = int(input())
S = input()
mod = 10**9+7

if S[0] == 'W' or S[-1] == 'W':
    print(0)
    sys.exit()

op = [0]*(2*N)
op[0] = False
ct_L = 1
ans = 1
for i in range(1, 2*N):
    if S[i] == S[i-1]:
        if op[i-1] is False:
            op[i] = True
            ans *= ct_L
            ct_L -= 1
        else:
            op[i] = False
            ct_L += 1
    else:
        if op[i-1] is False:
            op[i] = False
            ct_L += 1
        else:
            op[i] = True
            ans *= ct_L
            ct_L -= 1
    ans %= mod

ct_L, ct_R = Counter(op).values()
if ct_L != ct_R:
    print(0)
    sys.exit()


print(factorial(N) * ans % mod)
