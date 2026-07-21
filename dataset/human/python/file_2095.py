def main():
    from collections import Counter

    MOD = 10 ** 9 + 7

    N = int(input())
    S = input()

    ctr = Counter(S)

    ret = 1
    for count in ctr.values():
        ret = (ret * (count + 1)) % MOD
    print(ret - 1)


if __name__ == '__main__':
    main()
