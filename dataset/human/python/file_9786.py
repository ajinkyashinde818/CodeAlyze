def solve(n, k, a):
    S = set()
    x = 1
    S.add(x)
    loop_start = -1
    d = -1
    for i in range(n):
        x = a[x-1]
        if x in S:
            loop_start = x
            d = i+1
            break
        S.add(x)
    in_loop = False
    x, T = 1, 0
    for i in range(n):
        if x == loop_start:
            if in_loop:
                break
            in_loop = True
        if in_loop:
            T += 1
        x = a[x-1]
    if k > n:
        k = (k - d) % T + d
    x = 1
    for i in range(k):
        x = a[x-1]
    return x

n, k = map(int, input().split())
a = list(map(int, input().split()))
print(solve(n, k, a))
