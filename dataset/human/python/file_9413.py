def task(n, k, a):
    cache = [0] * (n + 1)
    pos = 1
    sequence = [1]
    cache[1] = pos
    index = 1
    prefix = 0
    ks = k

    while True:
        index += 1
        nxt = a[pos - 1]

        if cache[nxt] != 0:
            prefix = cache[nxt] - 1
            cycle = sequence[prefix:]
            break

        sequence.append(nxt)
        cache[nxt] = index
        pos = nxt

        ks -= 1

        if ks == 0:
            print(nxt)
            return

    target = (k - prefix) % len(cycle)
    print(cycle[target])


n, k = map(int, input().split())
a = list(map(int, input().split()))
task(n, k, a)
