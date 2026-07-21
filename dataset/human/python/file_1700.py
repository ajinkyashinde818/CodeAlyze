import sys

N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]

for y in range(N-M+1):
    for x in range(N-M+1):
        for k in range(M):
            if A[y+k][x:x+M] != B[k]:
                break
        else:
            print("Yes")
            sys.exit()
print("No")
