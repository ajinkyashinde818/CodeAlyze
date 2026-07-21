n = int(input())
m = n
r = []
for i in range(2, n + 1):
    if i ** 2 > n:
        break
    if m % i == 0:
        c = 0
        while m % i == 0:
            m //= i
            c += 1
        r.append((i, c))
if m > 1:
    r.append((m, 1))
def calc(x):
    ans = 0
    for i in range(1, x + 1):
        if (1 + i) * i // 2 <= x:
            ans = i
        else:
            break
    return ans
ans = 0
for u, v in r:
    ans += calc(v)
print(ans)
