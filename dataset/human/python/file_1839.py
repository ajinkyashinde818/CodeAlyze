import itertools

def solve(n, m, a, b):
    for i, j in itertools.product(range(n - m + 1), repeat=2):
        if all(a[i + x][j + y] == b[x][y] for x, y in itertools.product(range(m), repeat=2)): return "Yes"
    return "No"


if __name__ == '__main__':
    n, m = map(int, input().split())
    a = [[token for token in input()] for _ in range(n)]
    b = [[token for token in input()] for _ in range(m)]

    ans = solve(n, m, a, b)
    print(ans)
