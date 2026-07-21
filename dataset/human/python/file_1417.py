def abc067_c():
    n = int(input())
    a = list(map(int, input().split()))
    x = a[0]
    y = sum(a[1:])
    del a[0]
    del a[-1]
    diff = abs(x - y)
    for v in a:
        x += v
        y -= v
        if abs(x - y) < diff:
            diff = abs(x - y)
    print(diff)


abc067_c()
