D, G = map(int, input().split(" "))
p = [0] * D
c = [0] * D
for i in range(D):
    p[i], c[i] = map(int, input().split(" "))


def solve(G, i):
    """100i点以下の問題だけでGを達成する最小問題数"""
    if i <= 0:
        return 1e9
    n = min(int(G/(100*i)), p[i-1])
    s = 100 * i * n
    if n == p[i-1]:
        s += c[i-1]
    if G > s:
        n += solve(G-s, i-1)
    return min(n, solve(G, i-1))

print(solve(G, D))
