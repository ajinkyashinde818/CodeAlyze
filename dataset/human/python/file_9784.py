def solve():
    n,k=map(int,input().split())
    a=[-1]+list(map(int,input().split()))

    stp=[-1]*(n+1)

    vis=1
    stp[1]=0
    while k >= 0 :
        if k==0 :
            return vis
        nxt=a[vis]
        if stp[nxt] == -1 :
            stp[nxt]=stp[vis]+1
            vis=nxt
            k-=1
        else:
            loop=stp[vis]+1-stp[nxt]
            k%=loop
            for i in range(0,k) :
                vis=a[vis]
            return vis

print(solve())
