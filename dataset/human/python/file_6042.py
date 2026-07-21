import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    ans = 0
    for i in range(N - 1):
        ans += B[A[i] - 1]

        if A[i] + 1 == A[i+1]:
            ans += C[A[i] - 1]

    ans += B[A[-1] -1]

    print(ans)



if __name__ == "__main__":
    main()
