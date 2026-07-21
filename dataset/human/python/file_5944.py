def to(A,B,C):
    N=len(A)
    t=B[N-1]
    for i in range(N-1):
        t+=B[i]
        if A[i+1]==A[i]+1:
            t+=C[A[i]-1]
    return t
N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))
print(to(A,B,C))
