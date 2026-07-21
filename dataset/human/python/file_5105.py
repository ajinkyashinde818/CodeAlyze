def resolve():
    n,m = map(int, input().split())
    d = {}
    for i in range(m):
        a,b = map(int, input().split())
        if a not in d:
            d[a] = {}
        if b not in d:
            d[b] = {}
        d[a][b] = d[b][a] = 1

    if 1 not in d or n not in d:
        print('IMPOSSIBLE')
        return

    for a in d[1].keys():
        if a in d[n]:
            print('POSSIBLE')
            break
    else:
        print('IMPOSSIBLE')

if __name__ == '__main__':
    resolve()
