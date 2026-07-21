import sys

def solve():
    input = sys.stdin.readline
    N = int(input())
    A = [int(a) for a in input().split()]
    sumA = [0] * (N + 1)
    for i, a in enumerate(A): sumA[i+1] = sumA[i] + A[i]
    Ans = 100000000000000000
    for i in range(N - 1):
        Ans = min(Ans, abs(sumA[i + 1] - (sumA[N] - sumA[i + 1])))
    print(Ans)


    return 0

if __name__ == "__main__":
    solve()
