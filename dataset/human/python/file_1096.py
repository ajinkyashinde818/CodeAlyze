mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    B.reverse()
    idx = []
    x = -1
    for i in range(N):
        if A[i] == B[i]:
            idx.append(i)
            x = A[i]
    if len(idx) == 0:
        print("Yes")
        print(*B)
    else:
        l = 0
        r = N-1
        for i in idx:
            if A[l] != x and B[l] != x:
                B[l], B[i] = B[i], B[l]
                l += 1
            else:
                if A[r] != x and B[r] != x:
                    B[r], B[i] = B[i], B[r]
                    r -= 1
                else:
                    print("No")
                    exit()
        print("Yes")
        print(*B)


if __name__ == '__main__':
    main()
