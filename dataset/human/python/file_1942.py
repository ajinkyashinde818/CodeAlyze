n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]


def solve():
    for i in range(n - m + 1):
        for j in range(n - m + 1):
            c = ""
            for k in range(m):
                c += a[i + k][j : j + m]
            if "".join(b) == c:
                print("Yes")
                return
    print("No")


solve()
