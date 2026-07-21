def factorize(n):
    lst = []
    tmp = n

    for i in range(2, int(n ** 0.5) + 1):
        if tmp % i == 0:
            cnt = 0
            while tmp % i == 0:
                tmp //= i
                cnt += 1
            lst.append([i, cnt])

    if tmp != 1:
        lst.append([tmp, 1])

    return lst


def main():
    n = int(input())

    lst = factorize(n)
    ans = 0

    for l in lst:
        for i in range(1, 10 ** 6 + 1):
            if i * (i + 1) // 2 > l[1]:
                ans += i - 1
                break

    print(ans)


if __name__ == "__main__":
    main()
