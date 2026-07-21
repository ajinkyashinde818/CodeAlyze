from itertools import accumulate

N = int(input())
a = list(map(int, input().split()))
A = list(accumulate(a))
ans = float('inf')
for i in range(N - 1):
    ans = min(ans, abs(A[i]-(A[N-1]-A[i])))
print(ans)
