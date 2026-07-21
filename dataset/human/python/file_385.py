import math
N = int(input())
A = list(map(int, input().strip().split()))
minus = 0
abs_min = abs(A[0])
sum = 0
for i in range(0, N):
    sum += abs(A[i])
    if A[i] < 0:
        minus += 1
    if abs(A[i]) < abs_min:
        abs_min = abs(A[i])
if minus % 2 != 0:
    sum -= abs_min*2
print("{}".format(sum))
