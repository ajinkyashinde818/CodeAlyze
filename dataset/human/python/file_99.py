R, G, B, N = map(int, input().split())

def is_integer_num(n):
    if isinstance(n, int):
        return True
    if isinstance(n, float):
        return n.is_integer()
    return False

ans = 0

for i in range(N + 1):
    for j in range(N + 1):
        t = (N - G * i - B * j)
        if is_integer_num(t / R) and t >= 0:
            ans += 1

print(ans)
