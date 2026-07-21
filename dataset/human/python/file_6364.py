from sys import stdin, setrecursionlimit


def main():
    input = stdin.buffer.readline
    n = int(input())
    if n % 2 != 0:
        print(0)
    else:
        f = [2] * 30
        for i in range(29):
            f[i + 1] = 5 * f[i]
        ans = 0
        for i in range(1, 30):
            ans += (n // f[i])
        print(ans)


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
