def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    ans = 0

    for a in A:
        ans += B[a-1]

    tmp = A[0]
    for i in range(1, N):
        if A[i] - tmp == 1:
            ans += C[tmp-1]
        tmp = A[i]
    print(ans)


if __name__ == '__main__':
    main()
