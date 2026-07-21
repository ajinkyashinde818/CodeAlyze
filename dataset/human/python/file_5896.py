n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

def actual(n, A, B, C):
    bonus_point = 0

    for i in range(n - 1):
        if A[i + 1] - A[i] == 1:
            bonus_point += C[A[i] - 1]

    return sum(B) + bonus_point

print(actual(n, A, B, C))
