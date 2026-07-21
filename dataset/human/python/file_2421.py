d, g = map(int, input().split(' '))
p = []
c = []
for _ in range(d):
    p_, c_ = map(int, input().split(' '))
    p.append(p_)
    c.append(c_)

sum_p = []
for i in range(d):
    sum_p.append((i + 1) * 100 * p[i] + c[i])


def ans(g, t):
    if t <= 0:
        return float('inf')
    n = min(int(g / (100 * t)), p[t-1])
    s = 100 * t * n

    if n == p[t-1]:
        s = sum_p[t-1]
    if g > s:
        n += ans(g - s, t - 1)

    return min(n, ans(g, t - 1))


print(ans(g, d))
