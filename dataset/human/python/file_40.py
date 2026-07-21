def sol():
    r,g,b,n=map(int,input().split())
    ans=chk=0
    for i in range(n+1):
        for j in range(n+1):
            if (i*r+j*g)>n: break
            if (n-(i*r+j*g))%b==0:
                ans+=1
    print(ans)
if __name__ == '__main__':
    sol()
