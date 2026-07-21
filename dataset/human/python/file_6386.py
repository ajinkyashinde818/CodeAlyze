import sys
sys.setrecursionlimit(10**9)
INF=10**18
def input():
    return sys.stdin.readline().rstrip()

def main():
    N=int(input())
    if N%2==0:
        c=N//10
        tmp=c
        ans=0
        z=0
        while tmp > 0:
            ans+=tmp
            tmp=tmp//5
    else:
        ans=0
    print(ans)

if __name__ == '__main__':
    main()
