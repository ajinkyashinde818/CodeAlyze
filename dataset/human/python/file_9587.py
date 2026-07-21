import sys

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    N, K = map(int, input().split())
    A = [0] + list(map(int, input().split()))
    cur = 1
    visited = [-1] * (N + 1)
    visited[cur] = 0
    for i in range(1, K + 1):
        next = A[cur]
        if cur == next:
            print(next)
            return
        elif visited[next] != -1:
            mod = i - visited[next]
            start = visited[next]
            break
        else:
            visited[next] = visited[cur] + 1
            cur = next
    else:
        print(next)
        return

    K = (K - start) % mod
    print(visited.index(K + start))


if __name__ == "__main__":
    main()
