n = int(input())
al = list(map(int,input().split()))

import itertools
ac_al = list(itertools.accumulate(al))

ans = float("inf")  

for a in ac_al[:n-1]:
    tmp = abs((ac_al[-1] - a) - a)
    ans = min(ans, tmp)

print(ans)
