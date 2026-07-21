import math
import os
mod = 10**9 + 7
N = int(input())
S = input()

operations = ["L" for i in range(len(S))]
operations[len(S)-1] = "R"

for i in range(1, len(S)):
    if S[i-1] == S[i]:
        if operations[i-1] == "L":
            operations[i] = "R"
        else:
            operations[i] = "L"
    else:
        operations[i] = operations[i-1]
if S[0] == "W" or S[-1] == "W" or operations[-1] == "L":
    print(0)
    os.sys.exit()

ans = 1
cnt_r = 0
cnt_l = 0
for ope in operations:
    if ope == "R":
        ans *= (cnt_l - cnt_r) % mod
        ans %= mod
        cnt_r += 1
    else:
        cnt_l += 1
if cnt_l != cnt_r:
    print(0)
    os.sys.exit()
print(ans*math.factorial(N)%mod)
