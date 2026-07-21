import sys

input = sys.stdin.readline


def main():
    N = int(input())
    a = list(map(int, input().split()))

    S = [0] * N
    S[0] = a[0]
    for i in range(N - 1):
        S[i + 1] = S[i] + a[i + 1]

    ans = float("inf")
    for i in range(N - 1):
        x = S[i]
        y = S[-1] - x
        cost = abs(x - y)
        if cost < ans:
            ans = cost

    print(ans)


if __name__ == "__main__":
    main()
