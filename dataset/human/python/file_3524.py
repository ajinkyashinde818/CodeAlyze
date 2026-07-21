n = int(input())


def p(x):
    a = []
    i = 2
    while True:
        if x % i == 0:
            j = 0
            while x % i == 0:
                x //= i
                j += 1
            a.append((i, j))
        if i * i > x:
            break
        i += 1
    if x != 1:
        a.append((x, 1))
    return a


ans = 0
for _, j in p(n):
    i = 1
    while j >= i:
        j -= i
        i += 1
        ans += 1
print(ans)
