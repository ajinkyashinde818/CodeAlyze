import sys
input = sys.stdin.readline


def readstr():
    return input().strip()


def readint():
    return int(input())


def readnums():
    return map(int, input().split())


def readstrs():
    return input().split()


def main():
    N = readint()
    if N % 2:
        print(0)
    else:
        ans = 0
        i = 1
        while N >= 5 ** i:
            ans += (N // 5 ** i) // 2
            i += 1
        print(ans)


if __name__ == "__main__":
    main()
