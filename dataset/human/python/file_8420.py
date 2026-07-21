import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    K, N, *A = map(int, read().split())

    A.append(A[0] + K)
    B = [0] * N
    for i in range(N):
        B[i] = A[i + 1] - A[i]

    ans = K - max(B)

    print(ans)
    return


if __name__ == '__main__':
    main()
