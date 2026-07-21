import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

MOD = 10**9+7

N = int(input())
S = list(input().rstrip())

if S[0] == "W" or S[-1] == "W":
    print(0)
    sys.exit()

LR = [0 for i in range(2*N)]
count0 = 1
count0_raw = 1
ans = 1
for i in range(1, 2*N):
    if LR[i-1] == 0:
        if S[i] == S[i-1]:
            LR[i] = 1
        else:
            LR[i] = 0
    else:
        if S[i] == S[i-1]:
            LR[i] = 0
        else:
            LR[i] = 1

    if LR[i] == 0:
        count0 += 1
        count0_raw += 1
    else:
        ans *= count0
        ans %= MOD
        count0 -= 1

if count0_raw != N:
    print(0)
    sys.exit()

N_k = 1
for i in range(N):
    N_k *= i+1
    N_k %= MOD

print(ans*N_k%MOD)
