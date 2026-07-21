N, M = [int(_) for _ in input().split()]
A = [input() for i in range(N)]
B = [input() for i in range(M)]

def check(N, M, A, B):
    for i in range(N - M + 1):
        for j in range(N - M + 1):
            if all(a[j:j+M] == b for a, b in zip(A[i:i+M], B)):
                return True
    return False

if check(N, M, A, B):
    print("Yes")
else:
    print("No")
