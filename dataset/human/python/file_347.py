from math import fabs

N = int(input())
A = list(map(int, input().split()))

fu_count = 0
for i in range(N):
    if A[i] < 0:
        fu_count += 1

goukei = sum(fabs(a) for a in A)

if fu_count % 2 == 1:
    goukei -= 2 * min(fabs(a) for a in A)
print(int(goukei))
