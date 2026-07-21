n, m = map(int, input().split())

c = [[] for i in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    c[a].append(b)


def d(s, cnt):
    if s == n and cnt <= 2:
        print('POSSIBLE')
        exit()
    else:
        for i in c[s]:
            d(i, cnt + 1)


d(1, 0)
print('IMPOSSIBLE')
