from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))
A = list(accumulate(A))
answer = abs((A[-1] - A[0]) - A[0])
for i in range(N - 1):
    L = A[-1] - A[i]
    K = abs(L - A[i])
    if K < answer:
        answer = K


print(answer)
