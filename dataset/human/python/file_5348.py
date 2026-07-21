import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    from collections import defaultdict, deque
    n, m = map(int, readline().split())
    edge = defaultdict(set)

    for _ in range(m):
        a, b = map(int, readline().split())
        edge[a].add(b)
        edge[b].add(a)

    for u in edge[1]:
        if n in edge[u]:
            print("POSSIBLE")
            sys.exit()

    print("IMPOSSIBLE")

if __name__ == '__main__':
    main()
