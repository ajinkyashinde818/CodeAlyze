import itertools
n = int(input())
a = list(itertools.accumulate(list(map(int, input().split()))))
ans = 10000000000000
sum_a = a[-1]
for i in range(n-1):
  ans = min(ans,abs(sum_a - 2 * a[i]))
print(ans)
