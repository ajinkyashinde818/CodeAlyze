def resolve():
    n, g = map(int, input().split())
    a = list(map(int, input().split()))
    ar = [-1] * n
    k = 0
    now = 0
    for i in range(n+1):
        if ar[now] == -1:
            ar[now] = k
            now = a[now]-1
            k += 1
        else:
            start = ar[now]
            startnode = now
            end = k
    if g <= start:
        ans = 0
        for i in range(n):
            if ar[i] == g:
                ans = i+1
    else:
        g -= start
        g %= (end-start)
        now = startnode
        for i in range(g):
            now = a[now]-1
        ans = now + 1
    print(ans)
resolve()
