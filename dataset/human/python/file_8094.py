import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    K, S = map(int, readline().split())

    ans = 0
    for i in range(K + 1):
        for j in range(K + 1):
            if 0 <= S - i - j <= K:
                ans += 1

    print(ans)
    return


if __name__ == '__main__':
    main()
