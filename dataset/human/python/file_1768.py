def main():
    n,m=map(int,input().split())
    A=[list(input()) for _ in range(n)]
    B=[list(input()) for _ in range(m)]
    for i in range(n-m+1):
        for j in range(n-m+1):
            tmp=[]
            for k in range(m):
                tmp.append(A[i+k][j:j+m])
            if B==tmp:
                print('Yes')
                return
    print('No')
main()
