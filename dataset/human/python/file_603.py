import math

N = int(input())
A = list(map(int, input().strip().split(' ')))
B = []

sum_A = abs(A[0])
min_A = abs(A[0])
mins = 1 if A[0] < 0 else 0
for i in range(1, N):
    sum_A += abs(A[i])
    min_A = min(min_A, abs(A[i]))
    if A[i] < 0:
        mins += 1 if A[i] < 0 else 0

if mins % 2 == 0:
    print(sum_A)
else:
    print(sum_A-min_A*2)
