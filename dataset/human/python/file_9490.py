import math
from collections import defaultdict


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    visited = [-1 for _ in range(N)]
    visited[0] = 0

    current = 0
    th = -1
    per_loop = -1
    for i in range(1, N+1):
        current = A[current] - 1

        if visited[current] >= 0:
            # print(i, current, visited[current])
            per_loop = i - visited[current]
            th = visited[current]
            break
        else:
            visited[current] = i

    current = 0
    # print(th, per_loop)

    if K < th:
        num_rep = K
    else:
        num_rep = th + (K - th) % per_loop

    for i in range(num_rep):
        current = A[current] - 1

    print(current + 1)


if __name__ == '__main__':
    main()
