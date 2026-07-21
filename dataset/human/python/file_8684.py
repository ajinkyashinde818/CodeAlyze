import math
a , b = map(int,input().split())
res = list(map(int,input().split()))
res2 = []
if len(res) == 1:
    print(0)
else:
    for i in range(len(res)-1):
        aa = res[i+1] - res[i]
        res2.append(aa)
    if res[0] == 0:
        res2.append(a-res[-1])
    else:
        res2.append(res[0] + (a - res[-1]))
print(sum(res2) - max(res2))
