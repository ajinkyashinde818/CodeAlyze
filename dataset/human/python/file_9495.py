N,K=map(int,input().split())
A=[int(i)-1 for i in input().split()]
def times(X,Y):
    return [X[Y[i]] for i in range(N)]
def exponen(X,n):
    if n==0:
        return [i for i in range(N)]
    if n==1:
        return X
    if n%2==0:
        Y=exponen(X,n//2)
        return times(Y,Y)
    if n%2==1:
        Y=exponen(X,n//2)
        return times(times(Y,Y),X)
B=exponen(A,K)
print(B[0]+1)
