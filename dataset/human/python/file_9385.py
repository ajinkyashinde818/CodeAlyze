mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    LV = K.bit_length()
    nxt = [[0] * (LV+1) for _ in range(N+1)]
    for i in range(N):
        nxt[i+1][0] = A[i]
    for lv in range(1, LV+1):
        for i in range(1, N+1):
            nxt[i][lv] = nxt[nxt[i][lv-1]][lv-1]

    i = 1
    for j in range(LV+1):
        if K >> j & 1:
            i = nxt[i][j]
    print(i)


if __name__ == '__main__':
    main()
