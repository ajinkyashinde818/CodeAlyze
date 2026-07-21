from collections import defaultdict
import bisect as bs
MOD = 10**9 + 7
L = int(input())
S = input()
dic, l_dic = defaultdict(list), {}
for i in range(L):
    dic[S[i]].append(i)
ans = 0
for key in dic:
    l_dic[key] = len(dic[key])
for i in range(L):
    sub = 1
    for key in dic:
        if key == S[i]:
            continue
        sub = sub * (l_dic[key] - bs.bisect_right(dic[key], i) + 1) % MOD
    ans = (ans + sub) % MOD
print(int(ans))
