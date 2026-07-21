import math
input = raw_input

N = int(input())
A = list(map(int, input().split(" ")))
B = list(map(int, input().split(" ")))
C = list(map(int, input().split(" ")))

x = sum(B)
for i in range(1, N):
    if A[i] - A[i-1] == 1:
        x += C[A[i-1]-1]
print(x)
