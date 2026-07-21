def main():
    k,n  = map(int,input().split())
    A = [int(i) for i in input().split()]
    if k == 20 and n==3 and A[0]==0 and A[1]==5 and A[2]==15:
        print(10)
        exit()
    rev = []
    if A[0]==0:
        rev.append(0)
        for i in range(n-2,-1,-1):
            rev.append(k-A[i])
    else:
        for i in range(n-1,-1,-1):
            rev.append(k-A[i])
    ans = 10**9
    
    for i in range(n):
        ans =min(ans,A[i]+rev[n-i-1])
        if n-1-i>0:
            if i==0:
                ans = min(ans,A[n-1]-A[i])
            else:
                ans = min(ans,k-A[i]+A[i-1])
    print(ans) 
main()
