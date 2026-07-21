import sys
input = sys.stdin.readline
N, M = [int(x) for x in input().split()]
A = []
for _ in range(N):
    A.append(list(input().rstrip()))
B = []
for _ in range(M):
    B.append(list(input().rstrip()))
n = len(A[0])
m = len(B[0])
def search(point):
    x, y = point
    for i in range(M):
        if y > N - 1:
            return 0
        a = A[y][x:x + m]
        if a != B[i]:
            return 0
        y += 1
    return 1
for i in range(N):
    for j in range(n):
        if search([i, j]):
            print("Yes")
            sys.exit()
print("No")
