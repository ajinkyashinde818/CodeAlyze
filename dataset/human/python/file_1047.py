MOD = 10**9 + 7
import sys
input = sys.stdin.readline
N = int(input())
S = input().strip()

LR = []
d = 0
for s in S:
    if s == 'B':
        if d % 2:
            LR.append('R')
            d -= 1
        else:
            LR.append('L')
            d += 1
    else:
        if d % 2:
            LR.append('L')
            d += 1
        else:
            LR.append('R')
            d -= 1
    if d < 0:
        print(0)
        exit()
if not d == 0:
    print(0)
    exit()

ans = 1
d = 0
for m in LR:
    if m == 'L':
        d += 1
    else:
        ans *= d
        ans %= MOD
        d -= 1

for i in range(N):
    ans *= (i+1)
    ans %= MOD
print(ans)
