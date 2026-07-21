from collections import defaultdict
from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    a, i = [1], 0
    for _ in [0] * N:
        a.append(A[i])
        i = A[i] - 1

    if K <= N:
        print(a[K])
        return

    n = defaultdict(list)
    for i, v in enumerate(a):
        if n[v]:
            n[v].append(i)
            break
        n[v].append(i)
    l, r = n[v][0], n[v][1]
    loop = a[l:r]
    K -= l
    n = K % (r - l)
    print(loop[n])


main()
