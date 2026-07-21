from collections import defaultdict


def main():
    N, M = map(int, input().split())
    ab = [list(map(int, input().split())) for _ in range(M)]

    g = defaultdict(list)

    for n in ab:
        g[n[0]].append(n[1])

    if 1 not in g:
        print('IMPOSSIBLE')
        exit()

    for i in g[1]:
        if i not in g:
            continue
        for j in g[i]:
            if j == N:
                print('POSSIBLE')
                exit()

    print('IMPOSSIBLE')


if __name__ == "__main__":
    main()
