from itertools import accumulate
n = int(input())
a = [int(item) for item in input().split()]
cumsum = list(accumulate(a))

ans = 10 ** 20 
for i in range(n-1):
    ans = min(ans, abs(cumsum[n-1] - cumsum[i]*2))

print(ans)
