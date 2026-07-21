def main():
    k, n = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    a_ = [k - a[-1] + a[0]] + [a[i] - a[i - 1] for i in range(1, n)]

    print(k - max(a_))


if __name__ == "__main__":
    main()
