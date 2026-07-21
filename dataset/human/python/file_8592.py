from sys import stdin, setrecursionlimit


def main():
    input = stdin.buffer.readline
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    max = 0
    tmp = a[-1] - k
    for i in range(n):
        if a[i] - tmp > max:
            max = a[i] - tmp
        tmp = a[i]
    print(k - max)


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
