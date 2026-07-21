import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    from collections import Counter

    N = int(readline())
    a = list(map(int, readline().split()))
    b = list(map(int, readline().split()))

    cnt_a = Counter(a)
    cnt_b = Counter(b)

    acc_a = [0] * 200001
    acc_b = [0] * 200001

    for i in range(1, 200001):
        acc_a[i] = acc_a[i - 1] + cnt_a[i]
        acc_b[i] = acc_b[i - 1] + cnt_b[i]
        if cnt_a[i] + cnt_b[i] > N:
            return print("No")

    ans = 0
    for i in range(200000, 0, -1):
        score = acc_b[i] - acc_a[i - 1]
        ans = max(ans, score)

    print("Yes")

    res = b[ans:] + b[:ans]
    print(*res)

if __name__ == '__main__':
    main()
