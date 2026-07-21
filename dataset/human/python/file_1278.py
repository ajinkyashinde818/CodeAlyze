def resolve():
    N = int(input())
    A = list(map(int, input().split()))
    minabs = float("inf")
    tmpx = 0
    tmpy = sum(A)
    for i in range(N-1):
        tmpx += A[i]
        tmpy -= A[i]
        if abs(tmpx - tmpy) < minabs:
            minabs = abs(tmpx - tmpy)
    print(minabs)

if '__main__' == __name__:
    resolve()
