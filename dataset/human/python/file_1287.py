import itertools

N = int(input())
A = list(map(int,input().split()))
total = sum(A)
ACC = list(itertools.accumulate(A))

ans = 10 ** 10
for i in range(N-1):
  x = ACC[i]
  y = total - x
  ans = min(ans,abs(x - y))

print(ans)
