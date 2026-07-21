import sys

N, M = map(int, sys.stdin.readline().strip().split())

A = []
for _ in range(N):
    A.append(list(sys.stdin.readline().strip()))

B = []
for _ in range(M):
    B.append(list(sys.stdin.readline().strip()))

for i in range(N-M+1):
    for j in range(N-M+1):
        flag = True
        for y in range(M):
            for x in range(M):
                if A[i+y][j+x] != B[y][x]:
                    flag = False
            if not flag:
                break
        if flag:
            print("Yes")
            sys.exit()
print("No")
