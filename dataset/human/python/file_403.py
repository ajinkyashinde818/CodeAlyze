import sys

N = int(sys.stdin.readline())

A = list(map(int, sys.stdin.readline().split()))

abstotal = 0
count_minus = 0
abs_A = []
for i in range(N):
    abstotal += abs(A[i])
    abs_A.append(abs(A[i]))
    if A[i] < 0:
        count_minus += 1

ans = abstotal
if count_minus%2 == 1:
    ans = abstotal - 2 * min(abs_A)

print(ans)
