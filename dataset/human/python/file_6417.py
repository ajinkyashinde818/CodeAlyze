import sys

input = lambda: sys.stdin.readline().rstrip()


def solve():
    N = int(input())

    if N % 2 == 1 or N < 10:
        print(0)
        exit()

    ans = 0
    div = 10
    while div <= N:
        ans += N // div
        div *= 5

    print(ans)


if __name__ == '__main__':
    solve()
