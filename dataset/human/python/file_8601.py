def resolve():
    K, N = list(map(int, input().split()))
    A = list(map(int, input().split()))
    maxdiff = 0
    idx = None
    for i in range(N):
        if i == N-1:
            diff = (K+A[0]) - A[i]
        else:
            diff = A[i+1] - A[i]
        if maxdiff < diff:
            idx = i
            maxdiff = max(maxdiff, diff)
    print(K - maxdiff)

if '__main__' == __name__:
    resolve()
