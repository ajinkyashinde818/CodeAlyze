N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))


def solve():
    point = 0

    point += sum(B)

    for j in range(N - 1):
        if A[j + 1] == A[j] + 1:
            point += C[A[j] - 1]

    return point


print(solve())
