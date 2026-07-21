n, m = map(int, input().split())
a = [input() for i in range(n)]
b = [input() for i in range(m)]

def Check(x, y):
    flag = True
    for i in range(m):
        for j in range(m):
            if a[i + y][j + x] != b[i][j]: flag = False
    return flag

ans=False
for i in range(n - m + 1):
    for j in range(n - m + 1):
        if Check(i, j): ans = True
print('Yes' if ans else 'No')
