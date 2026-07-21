import sys

input = sys.stdin.readline


def main():
    N, M = [int(x) for x in input().split()]
    A = [input().strip() for _ in range(N)]
    B = [input().strip() for _ in range(N)]

    for i in range(N - M + 1):
        for i2 in range(N - M + 1):
            f = True
            for j in range(M):
                for k in range(M):
                    if A[j + i2][k + i] != B[j][k]:
                        f = False
                        break
                if not f:
                    break
            if f:
                print("Yes")
                return
    else:
        print("No")


if __name__ == '__main__':
    main()
