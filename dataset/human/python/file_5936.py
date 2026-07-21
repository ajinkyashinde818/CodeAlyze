def calc(N, A, B, C):
    score = sum(B)
    for i in range(N - 1):
        if (A[i] + 1 == A[i + 1]):
            score += C[A[i] - 1]
    return score


N = int(input())
A = [int(s) for s in input().split()]
B = [int(s) for s in input().split()]
C = [int(s) for s in input().split()]
print(calc(N, A, B, C))
