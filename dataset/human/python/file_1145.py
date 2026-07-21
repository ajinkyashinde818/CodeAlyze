def main():
    n=int(input())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))[::-1]
    Cnt=[0]*(n+1)
    for a,b in zip(A,B):
        Cnt[a]+=1
        Cnt[b]+=1
    if max(Cnt)>n:
        print('No')
        return
    l=0
    r=n-1
    for i in range(n):
        if A[i]==B[i]:
            if B[l]!=A[i] and A[l]!=A[i]:
                B[l],B[i]=B[i],B[l]
                l+=1
            else:
                B[r],B[i]=B[i],B[r]
                r-=1
    print('Yes')
    print(*B)
    return
    
if __name__=='__main__':
    main()
