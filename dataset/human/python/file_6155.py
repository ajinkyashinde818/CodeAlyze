import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    A, B, C = [int(x) for x in input().split()]
    ans = B + min(A + B, C)
    if C > A + B:
        ans += 1
    print(ans)


if __name__ == '__main__':
    main()
