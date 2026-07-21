def abc167d_teleporter():
    n, k = map(int, input().split())
    a = [0] + list(map(int, input().split()))
    cnts = [0] * (n + 1)
    i = 1
    nxt = 1
    while True:
        if cnts[a[nxt]] == 0:
            cnts[a[nxt]] = i
        else:
            val = (k - i) // (i - cnts[a[nxt]])
            k -= val * (i - cnts[a[nxt]])
        if i == k:
            break
        i += 1
        nxt = a[nxt]
    print(a[nxt])



abc167d_teleporter()
