import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, M = map(int, readline().split())
    A = [0] * N
    for i in range(N):
        A[i] = readline().strip()
    B = [0] * M
    for i in range(M):
        B[i] = readline().strip()

    for i in range(N - M + 1):
        for j in range(N - M + 1):
            ok = True
            for x in range(M):
                for y in range(M):
                    if A[i + x][j + y] != B[x][y]:
                        ok = False
                        break
                if not ok:
                    break
            if ok:
                print('Yes')
                return

    print('No')
    return


if __name__ == '__main__':
    main()
