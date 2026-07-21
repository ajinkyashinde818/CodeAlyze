from sys import stdin
def main():
    readline=stdin.readline
    K,N=map(int,readline().split())
    A=list(map(int,readline().split()))
    B=list()
    for i in range(N):
        if A[i]==0 or A[i]==K//2:
            B.append(A[i])
        else:
            B.append(A[i])
            B.append(A[i]-K)
    B.sort()
    mi=0
    ma=0
    res=K
    for i in range(len(B)):
        if i+N-1<=len(B)-1:
            mi=B[i]
            ma=B[i+N-1]
            res=min(res,ma-mi)
        else:
            break
    print(res)
if __name__=="__main__":
    main()
