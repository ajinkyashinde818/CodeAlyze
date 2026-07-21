import sys

N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]

for i in range(N - M + 1):
    for j in range(N - M + 1):
        matched = True

        for k in range(M):
            if A[i+k][j:j+M] == B[k]:
                continue
            else:
                matched = False
                break
    
        if matched:
            print('Yes')
            sys.exit()

print('No')
