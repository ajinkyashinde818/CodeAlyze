def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())

    g = tuple(set() for _ in range(N))
    for _ in range(M):
        a, b = (int(x) - 1 for x in input().split())
        g[a].add(b)
        g[b].add(a)

    intersect = {u_1 for u_1 in g[0]} & {u_N for u_N in g[N - 1]}
    print('POSSIBLE' if intersect else 'IMPOSSIBLE')


if __name__ == '__main__':
    main()
