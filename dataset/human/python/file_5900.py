import math

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
ans = int(0)
satis = int(0)

for i in range(N):
    satis += B[i]
    if i<N-1 and A[i]==A[i+1]-1:
        satis += C[A[i]-1]

ans = satis
print(ans)
