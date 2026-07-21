import sys
input = sys.stdin.readline

mod = 10**9+7


def main():
    N = int(input())
    X = list(map(int, input().split()))

    r1 = [1]
    r2 = [1]
    for i in range(N-1):
        r1.append(r1[i] * (i+1) % mod)
        r2.append(r2[i] * (N-1-i) % mod)
    r2.reverse()

    ans = 0
    r = 0
    for i in range(N-1):
        r += r1[i] * r2[i+1]
        ans += (X[i+1] - X[i]) * r
        ans %= mod
    print(ans)


if __name__ == '__main__':
    main()
