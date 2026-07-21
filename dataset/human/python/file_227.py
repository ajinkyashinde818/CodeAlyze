def check(n):
    i = 1
    while n > 0:
        n -= i
        if n == 0:
            return i
        i += 1
    return False


def solve(n):
    s = check(n)
    if s == False:
        print('No')
        return
    buf = [[s] + [0] * s for _ in range(s + 1)]
    t = s
    u = 1
    for i in range(s):
        buf[i][i + 1:i + t + 1] = list(range(u, u + t))
        for j in range(t):
            buf[i + j + 1][i + 1] = u + j
        u += t
        t -= 1
    print('Yes')
    print(s + 1)
    print('\n'.join(' '.join(map(str, b)) for b in buf))


n = int(input())
solve(n)
