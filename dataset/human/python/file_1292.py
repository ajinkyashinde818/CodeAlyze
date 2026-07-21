from itertools import accumulate
n = int(input())
aaa = list(map(int, input().split()))
a_sum = list(accumulate(aaa))
ans = 1e10
for i in range(n - 1):
    ans = min(ans, abs(a_sum[i] - a_sum[n - 1] + a_sum[i]))
print(ans)
