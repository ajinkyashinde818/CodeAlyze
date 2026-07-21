from collections import Counter

N = int(input())
S = input()
MOD = 10**9 + 7

ans, C = 0, Counter(S)
for i in range(N):
    sub_ans = 1
    for x in C:
        if x != S[i]:
            sub_ans = ((C[x] + 1) * sub_ans) % MOD
    ans = (ans + sub_ans) % MOD
    C[S[i]] -= 1
print(ans)
