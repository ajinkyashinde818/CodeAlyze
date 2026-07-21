import sys
input=sys.stdin.readline

def main():
    r,g,b,n=map(int,input().split())
    ans=0
    for i in range(n+1):
        for j in range(n+1):
            B=i*r+j*g
            if B>n: continue
            if (n-B)%b==0:
                ans+=1
    print(ans)

if __name__=="__main__":
    main()
