def resolve():
    N=int(input())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    C=list(map(int,input().split()))
    ans=0
    np=-199
    for i in range(N):
        n=A[i]
        ans+=B[n-1]
        if np+1==n:
            ans+=C[np-1]
        np=n
    print(ans)
resolve()
