import sys
input = sys.stdin.readline


def prime_factor_count(n):
    def count(n, p):
        cnt = 0
        while n % p == 0:
            n //= p
            cnt += 1
        np_cnt = 1
        while (cnt := cnt - np_cnt) >= 0:
            np_cnt += 1
        return n, np_cnt - 1

    n, cnt = count(n, 2)

    if n == 1:
        return cnt

    for i in range(3, int(n ** 0.5) * 1, 2):
        n, tmp_cnt = count(n, i)
        cnt += tmp_cnt
        if n == 1:
            break
    else:
        cnt += 1

    return cnt


def main():
    n = int(input())
    ans = prime_factor_count(n)
    print(ans)


if __name__ == '__main__':
    main()
