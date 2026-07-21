n, m = map(int, input().split())
s0 = [input() for _ in range(n)]
s1 = [input() for _ in range(m)]


def match(i0, i1):
    for j0 in range(m):
        for j1 in range(m):
            if s0[i0 + j0][i1 + j1] != s1[j0][j1]:
                return False
    return True


def answer():
    for i0 in range(n - m + 1):
        for i1 in range(n - m + 1):
            if match(i0, i1):
                return True
    return False


if answer():
    print("Yes")
else:
    print("No")
