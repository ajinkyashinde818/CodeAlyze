def resolve():
    N = int(input())
    A = [int(i) for i in input().split()]
    cntM = 0
    for i in range(N):
        if A[i] < 0:
            A[i] *= -1
            cntM += 1
    if 0 in A or cntM % 2 == 0:
        print(sum(A))
    else:
        print(sum(A) - min(A) * 2)

resolve()
