import sys

input = sys.stdin.readline


def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for i in range(M):
        a, b = map(lambda x: int(x) - 1, input().split())
        G[a].append(b)
        G[b].append(a)

    ans = "IMPOSSIBLE"
    for v in G[0]:
        if N - 1 in G[v]:
            ans = "POSSIBLE"
            break

    print(ans)


if __name__ == "__main__":
    main()
