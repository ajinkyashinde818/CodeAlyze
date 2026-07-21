from collections import Counter
n = int(input())
s = input()

mod = 10**9+7

scnt = Counter(s).most_common()
ans = 1

for i in range(len(scnt)):
    ans = ans*(scnt[i][1]+1)%mod
ans = (ans - 1 + mod)%mod
print(ans)
