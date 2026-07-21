from sys import stdin, setrecursionlimit

setrecursionlimit(10 ** 9)
INF = 1 << 60


def input():
    return stdin.readline().strip()


def main():
    N, K = map(int, input().split())
    A = [int(s) for s in input().split()]

    v = 1
    s = []
    order = [-1] * (N + 1)
    while order[v] == -1:
        order[v] = len(s)
        s.append(v)
        v = A[v - 1]
    l = order[v]
    c = len(s) - order[v]

    if K < l:
        print(s[K])
    else:
        print(s[l + (K - l) % c])

    return


if __name__ == '__main__':
    main()
