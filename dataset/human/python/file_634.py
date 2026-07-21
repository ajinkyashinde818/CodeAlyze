import sys

input = lambda: sys.stdin.readline().rstrip()


def solve():
    N = int(input())
    A = list(map(int, input().split()))
    pa = [abs(a) for a in A]

    count = 0
    for i in range(N):
        if A[i] < 0:
            count += 1

    if count % 2 == 0:
        ans = sum(pa)
    else:
        ans = sum(pa) - (min(pa) * 2)

    print(ans)


if __name__ == '__main__':
    solve()
