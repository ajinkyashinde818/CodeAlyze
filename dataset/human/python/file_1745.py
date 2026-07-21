n, m = map(int, input().split())

A = [input() for _ in range(n)]
B = [input() for _ in range(m)]

def issubset(l, u, r, d):
    for i, y in enumerate(range(u, d)):
        for j, x in enumerate(range(l, r)):
            res = A[y][x] == B[i][j]
            if not res:
                return False
    return True

if n == m:
    if issubset(0, 0, n, n):
        print("Yes")
    else:
        print("No")
    exit()

for y in range(n - m):
    for x in range(n - m):
        if issubset(x, y, x+m, y+m):
            print("Yes")
            exit()

print("No")
