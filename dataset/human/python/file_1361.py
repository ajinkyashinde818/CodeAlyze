N = int(input())
a = [int(i) for i in input().split()]

from itertools import accumulate

acum = list(accumulate(a))

answer = float("inf")
for i in range(N-1):
    answer = min(answer, abs(acum[-1]-acum[i]*2))

print(answer)
