import sys


n, m = map(int, input().split())
A = [input() for _ in range(n)]
B = [input() for _ in range(m)]

for i in range(n - m + 1):
    for j in range(n - m + 1):
        valid = True
        for k in range(m):
            for l in range(m):
                if A[i + k][j + l] != B[k][l]:
                    valid = False
                    break
            if valid is False:
                break
        if valid:
            print("Yes")
            sys.exit()
print("No")
