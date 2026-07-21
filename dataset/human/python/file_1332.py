from itertools import accumulate
n = int(input())
l = list(map(int,input().split()))
suml = sum(l)
accl = list(accumulate([0]+l))
ans = float('Inf')
for i in range(1,n):
    x = accl[i]
    j = abs(2*x - suml)
    ans = min(ans,j)
print(ans)
