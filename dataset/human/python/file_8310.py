def inpl(): return [int(i) for i in input().split()]
import sys

N = int(input())
A = inpl()

sumA = sum(A)
k = (N*(N+1)//2)
if sumA % k != 0:
    print('NO')
    sys.exit()
k = sumA // k
B = []
for i in range(N-1):
    B.append(A[i+1]-A[i]-k)
B.append(A[0]-A[N-1]-k)
flag = 0
ans = 'NO'
for i in B:
    if i%N != 0:
        break
    if i//N > 0:
        break
    flag -= i//N
else:
    if flag == k:
        ans = 'YES'
print(ans)
