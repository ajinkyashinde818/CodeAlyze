import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    N,R=map(int,input().split())
    print(R+100*max(0,(10-N)))

if __name__ == '__main__':
    main()
