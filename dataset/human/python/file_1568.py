import sys
N, M = map(int, input().split())

A = []
B = []
for i in range(N):
    A.append(input())
    
for j in range(M):
    B.append(input())
    

for b in range(N-M+1):
    for a in range(N-M+1):
        count = 0
        for i in range(M):
            if B[i] == A[i+b][a:a+M]:
                count += 1
        if count == M:
            print('Yes')
            sys.exit()
    
print('No')
