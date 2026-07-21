d, g = map(int, input().split())
point = []
for i in range(d):
    p, c = map(int, input().split())
    point.append([p, c])

def f(g, i):
    
    if i == -1:
        return 10000000
    n = min(g // ((i + 1) * 100), point[i][0])
    s = n * (i + 1) * 100
    if n == point[i][0]:
        s += point[i][1]
    if s < g:
        n += f(g - s, i - 1)
    return min(n, f(g, i - 1))
print(f(g, d-1))
