import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
input=lambda:sys.stdin.readline().rstrip()
def resolve():
    n=int(input())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    C=list(map(int,input().split()))
    ans=sum(B)
    for i in range(n-1):
        if(A[i+1]-A[i]==1):
            ans+=C[A[i]-1]

    print(ans)
resolve()
