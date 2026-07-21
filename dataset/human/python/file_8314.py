import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
s = sum(A)

if s%(N*(N+1)//2)!=0:
    print('NO')
    exit()

k = s//(N*(N+1)//2)
B = [A[(i+1)%N]-A[i] for i in range(N)]
B = list(map(lambda x: x-k, B))
cnt = 0

for Bi in B:
    if Bi>0 or Bi%N!=0:
        print('NO')
        exit()
        
    cnt += (-Bi)//N

if cnt==k:
    print('YES')
else:
    print('NO')
