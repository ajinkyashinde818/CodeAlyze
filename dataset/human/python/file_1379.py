import itertools

N = int(input())
A = list(map(int, input().split()))

B = list(itertools.accumulate(A))
ans = 10000000000
for i in range(N-1):
    if ans > abs(B[-1] - 2*B[i]):
        ans = abs(B[-1] - 2*B[i])

print(ans)
