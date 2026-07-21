import sys
input = sys.stdin.readline
def main():
    N = int(input())
    A = list(map(int, input().split()))
    X = [0]*(N+1)

    for i in range(1,N+1):
        X[i] += A[i-1] + X[i-1]
    ans  = float('INF') 
    for i in range(1,N):
        ans = min(ans,abs(X[N] - 2*X[i]))
    print(ans)

if __name__ == '__main__':
    main()
