nl = lambda: list(map(int, input().split()))
sl = lambda: input().split()
n = lambda: int(input())
s = lambda: input()

N, M = nl()
A = []
B = []
for i in range(N):
    A.append(s())
for i in range(M):
    B.append(s())

for i in range(N-M+1):
    col = A[i].find(B[0])
    if col >= 0:
        found = True
        for j in range(1, M):
            if A[i+j][col:col+M] != B[j]:
                found = False
                break
        if found:
            print('Yes')
            import sys
            sys.exit()

print('No')
