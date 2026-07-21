import numpy as np


def main():
    n = int(input())
    As = list(map(int, input().split()))
    cumsum = np.cumsum(As)
    ans = float("inf")
    for i in range(n-1):
        ans = min(ans, abs(cumsum[n-1]-2*cumsum[i]))
    print(ans)


if __name__ == "__main__":
    main()
