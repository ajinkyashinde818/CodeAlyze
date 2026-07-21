import sys
input = sys.stdin.readline


def read():
    N, K, S = map(int, input().strip().split())
    return N, K, S


def solve(N, K, S):
    ans = [0 for i in range(N)]
    for i in range(K):
        ans[i] = S
    for i in range(K, N):
        ans[i] = S % 10**9 + 1
    print(*ans)


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
