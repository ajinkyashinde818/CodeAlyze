import sys
INPUT = lambda: sys.stdin.readline().rstrip()
INT = lambda: int(INPUT())
LIST = lambda: list(map(int, INPUT().split()))
sys.setrecursionlimit(10 ** 9)


def main():
    N = INT()
    A = LIST()
    B = LIST()
    C = LIST()

    ans = 0
    for i in range(N):
        ans += B[A[i] - 1]
        if i != N-1 and A[i+1] - A[i] == 1: ans += C[A[i] - 1]

    print(ans)


if __name__ == '__main__':
    main()
