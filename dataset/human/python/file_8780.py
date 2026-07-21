import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    K, N = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    m = 0

    for a, b in zip(A, A[1:]):
        m = max(m, abs(a - b))

    m = max(m, A[0] + (K - A[-1]))

    print(K - m)



if __name__ == '__main__':
    main()
