import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)


def solve(N):
    if N % 2 == 1:
        return 0
    s = 5
    ans = 0
    while N > s:
        ans += N // s // 2
        s = s * 5
    return ans


def main():
    N = int(input())
    ans = solve(N)
    print(ans)


if __name__ == "__main__":
    main()
