import sys
def input(): return sys.stdin.readline().rstrip()
 
def main():
    n=int(input())
    if n%2==1:
        print(0)
    else:
        m=n//2
        ans=0
        for i in range(1,30):
            ans+=m//(5**i)
        print(ans)

 
if __name__=='__main__':
    main()
