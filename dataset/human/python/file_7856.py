import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    N,K,S=map(int,input().split())
    l=[S]*K+[S+1 if S+1<=10**9 else S-1]*(N-K)
    print(*l)
              

if __name__ == '__main__':
    main()
