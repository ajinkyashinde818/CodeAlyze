def main():
    n=int(input())
    a=list(map(int,input().split()))
    x=a[0]
    y=sum(a)-a[0]
    ans=abs(x-y)
    for i in range(1,n-1):
        x+=a[i]
        y-=a[i]
        ans=min(abs(x-y),ans)
    print(ans)
if __name__=="__main__":
    main()
