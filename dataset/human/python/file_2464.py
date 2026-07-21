from collections import deque

D, G = map(int, input().split())
G //= 100
p = [0]
c = [0]
for _ in range(D):
    pi, ci = map(int, input().split())
    p.append(pi)
    c.append(ci // 100)

q = deque()
q.append((0, 0, 0, " "))
ans = float("inf")
while len(q):
    i, m, g, s = q.pop()
    if i != D:
        q.append((i + 1, m, g, s + "0"))
        q.append((i + 1, m + p[i + 1], g + (i + 1)
                  * p[i + 1] + c[i + 1], s + "1"))
        continue

    if g < G:
        j = s.rfind("0")
        if j < 0:
            continue
        if g + j * (p[j] - 1) < G:
            continue
        m += (G - g + j - 1) // j  # ceil

    ans = min(ans, m)

print(ans)
