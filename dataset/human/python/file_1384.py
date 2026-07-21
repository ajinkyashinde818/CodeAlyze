from itertools import accumulate
n = int(input())
a = list(map(int, input().split()))
total = sum(a)
ans = 10**18
for i, cumsum in enumerate(accumulate(a), start=1):
    if i==n:
        break
    sunuke = cumsum
    araiguma = total - cumsum
    ans = min(ans, abs(sunuke - araiguma))
    
print(ans)
