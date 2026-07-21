import sys
input = sys.stdin.buffer.readline

def main():
    N,K,S = map(int,input().split())
    if S == 10**9:
        l = [S]*K+[S-1]*(N-K)
    else:
        l = [S]*K+[S+1]*(N-K)
    
    print(*l)
    
if __name__ == "__main__":
    main()
