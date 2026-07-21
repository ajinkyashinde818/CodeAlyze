def main ():
    n,m = map(int, input().split())
    ab = [list(map(int, input().split())) for _ in range(m)]
    g = [[] for _ in range(n+1)]
    for a,b in ab:
        g[a].append(b)
        g[b].append(a)
    if set(g[1]) & set(g[n]) != set([]):
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')


if __name__ == '__main__':
    main()
