import collections
N = int(input())
S = list(input())

s_list = collections.Counter(S)
s_list = list(s_list.items())
ans = 1
for i in range(len(s_list)):
    ans *= (s_list[i][1]+1)
    ans %= 10**9+7

print(ans-1)
