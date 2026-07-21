import sys

input = lambda: sys.stdin.readline().rstrip()


def solve():
    N = int(input())
    A = [0] + list(map(int, input().split()))
    B = [0] + list(map(int, input().split()))
    C = [0] + list(map(int, input().split()))

    ans = 0
    t = -10
    for i in range(1, N + 1):
        ans += B[A[i]]
        if A[i] == t + 1:
            ans += C[t]
        t = A[i]

    print(ans)


if __name__ == '__main__':
    solve()
