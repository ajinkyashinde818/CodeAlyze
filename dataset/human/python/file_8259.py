def solve():
    N = int(input())
    A = list(map(int, input().split()))
    Sum = sum(A)
    NN = N*(N+1)//2
    if Sum%NN != 0:
        return False
    k = Sum//NN
    cnt = 0
    for i in range(N):
        a = A[i]-A[i-1]
        if (k-a)%N != 0:
            return False
        cnt += (k-a)//N 
        if cnt > k:
            return False
    if cnt != k:
        return False
    for i in range(N):
        if A[i]<k:
            return False
    return True
if solve():
    print('YES')
else:
    print('NO')
