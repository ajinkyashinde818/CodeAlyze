import sys

def solve():
    input = sys.stdin.readline
    N = int(input())
    A = [int(a) for a in input().split()]
    DP = [[-10 ** 20, -10 ** 20] for _ in range(N)] #[-1が偶数, -1が奇数]
    DP[0] = [A[0], -1 * A[0]]
    for i in range(1, N):
        DP[i][0] = max(DP[i-1][0] + A[i], DP[i-1][1] - A[i])
        DP[i][1] = max(DP[i-1][0] - A[i], DP[i-1][1] + A[i])
    print(DP[N-1][0])
    #print(DP)


    return 0

if __name__ == "__main__":
    solve()
