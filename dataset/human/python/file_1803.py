def f(a, b):
    for x in range(n - m + 1):
        for y in range(n - m + 1):
            ok = True
            for i in range(m):
                for j in range(m):
                    if b[i][j] != a[i + x][j + y]:
                        ok = False
                    if not ok:
                        break
                if not ok:
                    break
            if ok:
                return 'Yes'
    return 'No'


n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]
print(f(a, b))
