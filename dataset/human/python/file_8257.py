import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().split()))

'''
import random
N = 30
A = [0]*N
for i in range(1000):
    n = random.randint(1,N)
    for j in range(N):
        A[(n-1+j)%N] += j+1
        '''

M = N*(N+1)//2
sumA = sum(A)

if sumA % M != 0:
    print('NO')
    exit()

diff = [x-y for x,y in zip(A[1:] + [A[0]], A)]

all_cnt = 0
while min(diff) < 0:
    cnt = 0
    for i in range(N):
        if diff[i] < 0:
            t = -(diff[i]//(N-1))
            cnt += t
            diff[i] += t*N
    diff = [d-cnt for d in diff]
    all_cnt += cnt*M
    if all_cnt > sumA:
        print('NO')
        exit()

N2 = sumA - all_cnt
if N2 % (M*N) == 0:
    print('YES')
else:
    print('NO')
