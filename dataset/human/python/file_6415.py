import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    N=I()
    if N%2==1:
        print(0)
        exit()
    
    ans=0
    
    for i in range(1,100):
        a=2*pow(5,i)
        ans+=N//a
        
    print(ans)
        
    
    

main()
