import sys
input = sys.stdin.readline
sys.setrecursionlimit(2 * 10**6)


def inpl():
    return list(map(int, input().split()))


def main():
    N, K = inpl()
    A = inpl()

    nn = 1
    n = 1
    i = 0
    while True:
        nn = A[nn - 1]
        nn = A[nn - 1]
        n = A[n - 1]

        if nn == n:
            break

    roop = set()
    roop.add(n)
    root = n
    while True:
        n = A[n - 1]
        roop.add(n)
        if root == n:
            break

    n = 1
    rest = []
    while n not in roop:
        n = A[n - 1]
        rest.append(n)

    # print(roop)
    # print(rest)
    if K <= len(rest):
        print(rest[K - 1])
    else:
        for i in range((K - len(rest)) % len(roop)):
            n = A[n - 1]
        print(n)

    return


if __name__ == '__main__':
    main()
