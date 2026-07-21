n, m = map(int, input().split())
A, B = [], []

for i in range(n):
    A.append(input())

for i in range(m):
    B.append(input())

def is_contain(i, b_pos):
    containing = True
    for k in range(1, m):
        if A[i+k][b_pos:(b_pos+len(B))] != B[k]:
            containing = False
    return containing

if n < m or len(A) < len(B):
    print("No")
    exit()

for i in range(n - m + 1):
    lineA = A[i]
    lineB = B[0]
    lineB_pos = lineA.find(lineB)
    if lineB_pos >= 0:
        if is_contain(i, lineB_pos):
            print("Yes")
            exit()

print("No")
