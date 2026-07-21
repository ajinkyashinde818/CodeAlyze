import sys
sys.setrecursionlimit(10**9)
INF=10**18
def input():
    return sys.stdin.readline().rstrip()

def main():
    N,M=map(int,input().split())
    A=[input() for _ in range(N)]
    B=[input() for _ in range(M)]
    for i in range(N-M+1):
        for j in range(N-M+1):
            for k in range(M):
                if A[i+k][j:j+M]!=B[k]:
                    break
            else:
                print('Yes')
                exit()
    print('No')

if __name__ == '__main__':
    main()
