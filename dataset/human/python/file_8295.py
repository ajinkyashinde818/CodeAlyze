import sys

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

def solve():
    N = int(input())
    A = [int(i) for i in input().split()]
    K, r = divmod(sum(A), N * (N+1) // 2)

    if r != 0:
        print('NO')
        return None

    dif = [A[(i + 1) % N] - A[i] for i in range(N)]

    for i in range(N):
        if dif[i] > K or (K - dif[i]) % N != 0:
            print('NO')
            return None

    print('YES')


if __name__ == '__main__':
    solve()
