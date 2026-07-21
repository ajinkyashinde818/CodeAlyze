n, k = map(int, input().split())
a = [int(i) for i in input().split()]


def answer():
    path = [1]
    visited = set([1])
    now = 1
    t = 0

    while True:
        if now == a[now - 1]:
            return now

        now = a[now - 1]
        t += 1

        if t == k:
            return now

        if now in visited:
            ti = path.index(now)
            tc = t - ti
            cycle = path[ti:]
            break
        else:
            path.append(now)
            visited.add(now)

    return cycle[(k - t) % tc]


print(answer())
