import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    K,S=MI()
    ans=0
    for x in range(K+1):
        for y in range(K+1):
            z=S-(x+y)
            if 0<=z<=K:
                ans+=1
    print(ans)

main()
