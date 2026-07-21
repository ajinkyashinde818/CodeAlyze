import math

N = int(input())
A = [int(elm) for elm in input().split(" ")] 

minus_count = 0
min_A = abs(A[0])
min_i = 0
for i in range(N):
    if A[i] < -1:
        minus_count += 1
    abs_a = abs(A[i])
    if min_A > abs_a:
        min_i = i
        min_A = abs_a

A2 = [abs(a) for a in A]
    
if minus_count % 2 == 0:
    out = sum(A2)
else:
    A2[min_i] *= -1
    out = sum(A2)

print(out)
