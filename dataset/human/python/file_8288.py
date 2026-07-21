import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(readline())
    a = list(map(int, readline().split()))
    x = n * (n + 1) // 2
    y = sum(a)

    if y % x != 0:
        return print("NO")

    b = [0] * n
    c = y // x
    for i in range(n):
        b[i] = a[i] - a[(i + 1) % n] + c

    p = [0] * n
    for i in range(n):
        if b[i] % n != 0 or b[i] < 0:
            return print("NO")
        else:
            p[i] = b[i] // n

    if sum(p) == c:
        print("YES")
    else:
        print("NO")


if __name__ == '__main__':
    main()
