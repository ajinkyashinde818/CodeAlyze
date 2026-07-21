import sys


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(10 ** 9)


def main():
    N = int(input())

    def F(N):
        if N & 1:
            return 0
        N //= 2
        x = 0
        while N:
            N //= 5
            x += N
        return x

    answer = F(N)
    print(answer)


if __name__ == "__main__":
    main()
