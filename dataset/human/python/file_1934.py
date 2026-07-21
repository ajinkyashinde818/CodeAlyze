n,m = map(int, input().split())
A = [None]*n
for i in range(n):
    A[i] = list(input())
B = [None]*m
for i in range(m):
    B[i] = list(input())

def solve(i,j):
    for k in range(m):
        for l in range(m):
            if A[i+k][j+l] != B[k][l]:
                return False
    return True # match

for i in range(n-m+1):
    for j in range(n-m+1):
        if solve(i,j):
            print("Yes")
            exit()
print("No")
