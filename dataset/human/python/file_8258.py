import sys
input = sys.stdin.buffer.readline

N = int(input())
A = list(map(int, input().split()))

sum_N = N * (N + 1) // 2
sum_A = sum(A)

if sum_A % sum_N != 0:
    print("NO")
    exit()
else:
    k = sum_A // sum_N

B = []
for i in range(N):
    if i + 1 != N:
        B.append(A[i + 1] - A[i] - k)
    else:
        B.append(A[0] - A[i] - k)

cnt = 0
for b in B:
    if b % N == 0 and b <= 0:
        k += b // N 
    else:
        print("NO")
        exit()

if k == 0:
    print("YES")
else:
    print("NO")
