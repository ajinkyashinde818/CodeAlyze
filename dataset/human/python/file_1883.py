n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]


def f():
    if a == b:
        return True
    for i in range(n - m):
        for j in range(n - m):
            for k in range(m):
                if a[i + k][j:j + m] != b[k]:
                    break
            else:
                return True
    return False

print("Yes" if f() else "No")
