n, m = map(int, input().split())
a = []
b = []
for i in range(n):
    a.append(list(input()))

for i in range(m):
    b.append(list(input()))


def ext(x, y):
    global a
    res = [[0 for _ in range(m)] for __ in range(m)]

    for i in range(m):
        for j in range(m):
            res[i][j] = a[i+x][j+y]

    return res


ans = "No"
for i in range(0, n - m + 1):
    for j in range(0, n - m + 1):
        if (ext(i, j) == b):
            ans = "Yes"

print(ans)
