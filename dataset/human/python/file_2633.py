d, g = map(int, input().split())
p_c = [0] + [list(map(int, input().split())) for _ in range(d)]


def function(g, i):
    if i == 0:
        return 1e9
    n = min(g // (i * 100), p_c[i][0])
    s = n * i * 100
    if n == p_c[i][0]:
        s += p_c[i][1]
    if s < g:
        n += function(g-s, i-1)
    return min(n, function(g, i-1))


print(function(g, d))
