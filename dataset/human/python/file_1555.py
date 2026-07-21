n, m = map(int, input().split())
a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(m)]

def comp(i, j):
    for x in range(m):
        for y in range(m):
            if a[i+x][j+y] != b[x][y]:
                return False
    return True

ans = 'No'
for i in range(n-m+1):
    for j in range(n-m+1):
        if comp(i, j):
            ans = 'Yes'
print(ans)
