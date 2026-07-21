def solve():
    r,g,b,n=map(int,input().split())
    ans=0
    for i in range(int(n/r)+1):
        for j in range(int((n-(i*r))/g)+1):
            num=n-(i*r+j*g)
            if num%b==0 and num>=0:
                ans+=1
    print(ans)
solve()
