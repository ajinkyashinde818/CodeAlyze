from sys import stdin, setrecursionlimit


def main():
    input = stdin.buffer.readline
    n, r = map(int, input().split())
    if n >= 10:
        print(r)
    else:
        print(r + 100 * (10 - n))


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
