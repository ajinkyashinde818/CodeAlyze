import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    R,G,B,N=MI()
    ans=0
    for r in range(0,N+1,R):
        for g in range(0,N+1-r,G):
            b=N-r-g
            if b%B==0:
                ans+=1
                
    print(ans)

main()
