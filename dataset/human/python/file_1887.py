import sys
N, M = map(int, input().split())
A = []
B = []
for _ in range(N):
    a1 = input()
    A.append(a1)
for _ in range(M):
    b1 = input()
    B.append(b1)
    
for i in range(N-M+1):
    for j in range(N-M+1):
        for k in range(M):
            if A[i+k][j:j+M] == B[k]:
                pass
            else:
                break
            if k == M-1:
                print("Yes")
                sys.exit()
print("No")
