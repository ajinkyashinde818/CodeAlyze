def calc(n, a, b, c):
    r = 0

    pre_x = -2
    for x in a:
        r += b[x-1]
        if pre_x + 1 == x:
            r += c[x-2]
        pre_x = x

    return r


n = int(input())  # 2-20
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

r = calc(n, a, b, c)
print(r)
