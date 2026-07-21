from collections import defaultdict
dic = defaultdict(lambda: 0)
K,S=[int(a) for a in input().split(" ")]
for x in range(0,K+1):
    for y in range(0,K+1):
        dic[S-x-y] += 1
ans = 0
for z in range(0, K+1):
    ans += dic[z]
print(ans)
