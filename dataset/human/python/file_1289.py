import sys
import itertools

input = sys.stdin.readline


def main():
    N = int(input())
    A = [int(x) for x in input().split()]

    X = list(itertools.accumulate(A))
    Y = sum(A)

    ans = float("inf")
    for i in range(N - 1):
        x = abs(X[i] - (Y - X[i]))
        ans = min(ans, x)

    print(ans)



if __name__ == '__main__':
    main()
