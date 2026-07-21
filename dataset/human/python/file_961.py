import sys
def main():
    n=int(input())
    s=input()
    MOD=10**9+7
    perm=1
    for i in range(1,n+1):
        perm=perm*i%MOD
    ans=1
    dp=[-1]*(2*n)

    dp[0]=1#L
    for i in range(1,2*n):
        if s[i]==s[i-1]:
            dp[i]=1-dp[i-1]
        else:
            dp[i]=dp[i-1]
    if s[0]=='W' or s[-1]=='W' or sum(dp)!=n:
        print(0)
        sys.exit()
    #print(dp)
    count=0
    for i in range(2*n):
        if dp[i]==1:
            count+=1
        else:
            ans*=count
            ans%=MOD
            count-=1
    print(ans*perm%MOD)

if __name__ == '__main__':
    main()
