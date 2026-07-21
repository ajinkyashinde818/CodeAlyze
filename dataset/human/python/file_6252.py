import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
def input(): return sys.stdin.readline().rstrip()

def main():
    N=list(input())
    N=list(reversed(list(map(int,N))))+[0]
    ans=0
    for i in range(len(N)):
        if N[i]>=6 or (N[i]==5 and N[i+1]>=5):
            ans+=10-N[i]
            N[i+1]+=1
        else:
            ans+=N[i]
    print(ans)

if __name__ == '__main__':
    main()
