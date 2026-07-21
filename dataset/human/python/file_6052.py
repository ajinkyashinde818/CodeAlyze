def q2():
    N = int(input())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]

    ans = 0
    pre_i = N
    for i in range(N):
        ans += B[A[i]-1]
        if A[i] == pre_i + 1:
            ans += C[A[i]-2]
        pre_i = A[i]
    print(ans)


if __name__ == '__main__':
    q2()
