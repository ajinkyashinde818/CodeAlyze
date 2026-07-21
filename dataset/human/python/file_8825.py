def a():
    S = input()

    if S[3] == S[2] and S[4] == S[5]:
        print("Yes")
    else:
        print("No")


def b():
    X = int(input())
    y_500 = (X // 500) * 1000
    y_5 = ((X - (y_500 / 2)) // 5) * 5
    print(int(y_500 + y_5))


def c():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))

    max_A_d = -1
    for i in range(len(A)):
        A_d = 0
        if i == 0:
            A_d = K - (A[-1] - A[0])
        else:
            A_d = (A[i] - A[i - 1])
        if max_A_d < A_d:
            max_A_d = A_d
    d = K - max_A_d
    print(d)


def d():
    print()


def e():
    print()


c()
