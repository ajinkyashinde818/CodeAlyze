from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    K, N = map(int, input().split())
    A = tuple(map(int, input().split()))

    d = K - A[-1] + A[0]
    for i in range(N - 1):
        d = max(d, A[i+1] - A[i])
    print(K - d)


main()
