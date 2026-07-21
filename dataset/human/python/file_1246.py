import sys

readline = sys.stdin.buffer.readline


def main():
    N = int(readline())
    A = list(map(int, readline().split()))

    D0 = A[0]
    D1 = sum(A[1:])
    M0 = [None] * (N-1)
    M0[0] = D0 - D1

    for i in range(1, N-1):
        M0[i] = M0[i-1] + 2 * A[i]

    M0 = list(map(lambda x: abs(x), M0))
    print(min(M0))


main()
