import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n, k = list(map(int, readline().split()))
    temp = [-1] + list(map(int, readline().split()))
    a = {i: temp[i] for i in range(1, n + 1)}

    cur = 1
    cnt = 0
    visited = {i: -1 for i in range(1, n + 1)}
    visited[1] = 0

    while True:
        cnt += 1
        cur = a[cur]
        if visited[cur] == -1:
            visited[cur] = cnt
        else:
            break

    start = cur
    st = visited[cur]
    gt = cnt
    period = gt - st
    t = k

    if t < st:
        cur = 1
        cnt = 0
        while cnt != t:
            cnt += 1
            cur = a[cur]
    else:
        t -= st
        t %= period
        cur = start
        cnt = 0
        while cnt != t:
            cnt += 1
            cur = a[cur]

    print(cur)


if __name__ == '__main__':
    main()
