import sys

def solve():
    input = sys.stdin.readline
    K, N = map(int, input().split())
    A = [int(a) for a in input().split()]
    longestL = A[0] + (K - A[N - 1])
    for i in range(N - 1):
        longestL = max(longestL, A[i+1] - A[i])
    print(K - longestL)


    return 0

if __name__ == "__main__":
    solve()
