def main():
    mod=10**9+7
    n=int(input())
    a=input()+'z'
    if a[0]=='W':
        print(0)
        return 0
    x=[]
    cnt=1
    for i in range(2*n):
        if a[i]==a[i+1]:
            cnt+=1
        else:
            x.append(cnt)
            cnt=1
    lx=len(x)
    if lx==1:
        ans=1
        for i in range(2,n+1):
            ans=ans*i%mod
        print(ans)
        return 0
    if x[0]%2==0 or x[-1]%2==0:
        print(0)
        return 0
    y=[1]
    now=1
    cnt=1
    for i in range(lx-1):
        if x[i]%2!=0:
            cnt+=now
            y.append(cnt)
        else:
            now*=-1
            cnt+=now
            y.append(cnt)
    if y[-1]>1 or 0 in y:
        print(0)
        return 0
    z=[1]+[y[i+1]-y[i] for i in range(lx-1)]
    ans=1
    for i in range(lx):
        if x[i]%2==0:
            ans=ans*pow(y[i],x[i]//2,mod)%mod
        else:
            ans=ans*pow(y[i],(x[i]-1)//2+(z[i]==-1),mod)%mod
    for i in range(2,n+1):
        ans=ans*i%mod
    print(ans)
main()
