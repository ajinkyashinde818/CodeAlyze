import sys; from collections import deque ; readline = sys.stdin.readline

N = int(readline())
A = list(map(lambda x:int(x)-1, readline().split()))
B = list(map(int, readline().split()))
C = list(map(int, readline().split()))

a = 0
for i in range(N - 1):
    if A[i + 1] == A[i] + 1:
        a += C[A[i]]

a += sum(B)

print(a)
