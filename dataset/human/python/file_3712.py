def gen_prime_decompositon(n):
    x = n
    d = 2
    cnt = 0
    while x % d == 0:
        x //= d
        cnt += 1
    if cnt != 0: yield cnt

    d = 3
    while d * d <= n:
        cnt = 0
        while x % d == 0:
            x //= d
            cnt += 1
        if cnt != 0: yield cnt
        d += 2

    if x > 1:
        yield 1


def main():
    from bisect import bisect_left
    from itertools import accumulate

    N = int(input())

    *acc, = accumulate(range(1, 40 + 1))

    ans = 0
    for cnt in gen_prime_decompositon(N):
        ans += bisect_left(acc, cnt + 1)  # acc上でcnt未満の個数=引ける回数

    print(ans)


if __name__ == '__main__':
    main()
