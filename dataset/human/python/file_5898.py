import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    N = int(readline())
    A = list(map(int, readline().split()))
    B = list(map(int, readline().split()))
    C = list(map(int, readline().split()))

    ans = 0
    prev = N + 100

    for i in range(N):
        x = A[i] - 1
        ans += B[x]
        if prev + 1 == x:
            ans += C[prev]
        prev = x

    print(ans)


if __name__ == '__main__':
    main()
