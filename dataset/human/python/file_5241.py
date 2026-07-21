def main():
    from collections import defaultdict
    n,m = map(int,input().split())
    G = defaultdict(set)
    for _ in range(m):
        a,b = map(int,input().split())
        G[a].add(b)
        G[b].add(a)

    flg = 0
    for i in G[1]:
        if n in G[i]:
            flg = 1
    if flg == 1:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')

main()
