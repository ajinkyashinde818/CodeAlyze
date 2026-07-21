from itertools import accumulate
n = int(input())
a = list(map(int, input().split()))
b = list(accumulate(a))
ans = 100000000000
SUM = sum(a)
for i in b[:-1]:
  tmp = abs(SUM - i * 2)
  if tmp < ans:
    ans = tmp
print(ans)
