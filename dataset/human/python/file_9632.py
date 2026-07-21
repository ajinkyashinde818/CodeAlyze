import sys
def f(A,N):
    INF=10**18+1
    C=[0 for _ in [0]*N]
    C[0],cp=1,0
    for i in range(2,N+2):
        if C[A[cp]]>0:return (A[cp],C[A[cp]]-1,i-C[A[cp]])
        else:C[A[cp]],cp=i,A[cp]
    return (-1,0,INF)
def main():
    N,K=tuple(map(int,sys.stdin.readline().split()))
    A=list(map(lambda x:int(x)-1,sys.stdin.readline().split()))
    a,n,m=f(A,N)
    (cp,X)=(0,K) if a==-1 or K<=n else (a,(K-n)%m)
    for _ in range(X):cp=A[cp]
    print(cp+1)
if __name__=='__main__':main()
