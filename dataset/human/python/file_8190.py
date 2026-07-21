import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    k, s = map(int, readline().split())
    ans = 0

    for x in range(k + 1):
        if s - x > 2 * k or s - x < 0:
            continue
        for y in range(k + 1):
            z = s - x - y
            if z > k or z < 0:
                continue
            ans += 1

    print(ans)


if __name__ == '__main__':
    main()
