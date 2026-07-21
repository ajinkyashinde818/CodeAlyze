def main():
    inf = 10 ** 14 + 1

    n = int(input())
    *a, = map(int, input().split())

    stay = 0  # -1を乗算しない
    done = -inf  # -1を乗算した

    for x in a:
        stay, done = max(stay + x, done - x), max(stay - x, done + x)

    print(stay)


if __name__ == '__main__':
    main()
