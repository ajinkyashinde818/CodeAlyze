n, m = map(int, input().split())
a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(m)]

def dfs(x: int, y: int, i: int, j: int) -> bool:
    if i-x == m:
        return True
    if j-y == m:
        return True

    if a[i][j] != b[i-x][j-y]:
        return False

    if not dfs(x, y, i, j+1):
        return False
    if not dfs(x, y, i+1, j):
        return False
    if not dfs(x, y, i+1, j+1):
        return False

    return True

ans = "No"
for i in range(n-m+1):
    for j in range(n-m+1):
        if a[i][j] == b[0][0]:
            x = i
            y = j
            if dfs(x, y, i, j):
                ans = "Yes"
                break

print(ans)
