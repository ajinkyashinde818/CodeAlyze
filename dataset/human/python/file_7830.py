def main():
    n, k, s = map(int, input().split(" "))
    array = []
    dummy = s + 1
    if s == 10 ** 9:
        dummy = s - 1
    if k <= n:
        array = [s for _ in range(k)]
        array += [dummy for _ in range(k, n)]
    print(" ".join(map(str, array)))


if __name__ == '__main__':
    main()
