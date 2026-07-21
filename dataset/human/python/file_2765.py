N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
D = [[False] * 51 for i in range(51)]
use = []


def calc(a, b, D):
    if a == b:
        return True
    d = {}
    stack = [a]
    while stack:
        u = stack.pop()
        if u == b:
            return True
        d[u] = 1
        for w in range(1, 51):
            if (u % w) in d:
                continue
            if D[u][u % w]:
                stack.append(u % w)

    return False


def check(n):
    D = [[False] * 51 for i in range(51)]
    for i in range(51):
        for k in range(1, n):
            D[i][i % k] = True
        D[i][i] = True

    for i in range(51):
        for j in use:
            D[i][i % j] = True

    for a, b in zip(A, B):
        if not calc(a, b, D):
            return True
    return False


if check(51):
    print(-1)
    exit()

ans = 0
for j in range(50, 0, -1):
    if check(j):
        use.append(j)
        ans += 2 ** j

print(ans)
