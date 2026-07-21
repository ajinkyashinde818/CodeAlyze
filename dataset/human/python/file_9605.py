import sys
input = sys.stdin.readline
sys.setrecursionlimit(200000)


def read():
    N, K = map(int, input().strip().split())
    A = list(map(int, input().strip().split()))
    return N, K, A


def solve(N, K, A, INF = 10**8):
    counts = [0 for i in range(N)]
    a = 1
    loop_init = -1
    loop_count = -1
    while True:
        counts[a-1] += 1
        if counts[a-1] == 2 and loop_count < 0:
            loop_count = 0
        elif counts[a-1] == 3:
            loop_count += 1
            break
        elif loop_count >= 0:
            loop_count += 1
        a = A[a-1]
    loop_init = sum([c == 1 for c in counts])

    a = 1
    if loop_init > K:
        for i in range(K):
            a = A[a-1]
    else:
        loop_k = (K - loop_init) % loop_count
        for i in range(loop_init + loop_k):
            a = A[a-1]
    return a


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
