from sys import stdin


def solve(N):
    if N % 2 == 1:
        return 0
    if N == 0:
        return 0

    a = N // 50
    b = N // 10

    ans = a + b

    for i in range(2, N):
        x = (5 ** i) * 10
        y = N // x
        if y == 0:
            break
        ans += y

    return ans


def main():
    N = int(stdin.readline().rstrip())
    result = solve(N)
    print(result)


if __name__ == "__main__":
    main()
