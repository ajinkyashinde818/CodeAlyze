from collections import defaultdict


def resolve():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 10 ** 9 * n
    acc = 0
    s = sum(a)
    for i in range(n - 1):
        acc += a[i]
        diff = abs(s - 2 * acc)
        if diff < ans:
            ans = diff
    print(ans)


if __name__ == "__main__":
    resolve()
