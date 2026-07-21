def b():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    satisfaction, pre_a = 0, -1
    for i in range(N):
        a = A[i] - 1
        satisfaction += B[a]
        if pre_a != -1 and pre_a + 1 == a:
            satisfaction += C[pre_a]

        pre_a = a

    print(satisfaction)


if __name__ == '__main__':
    b()
