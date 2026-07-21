def solve():
    r,g,b,n = map(int,input().split())
    ans = 0
    for i in range(n+1):
        if r*i>n:
            break
        for j in range(n+1):
            if g*j+r*i>n:
                break
            if (n-g*j-r*i)%b==0:
                ans+=1
    print(ans)
if __name__=='__main__':
    solve()
