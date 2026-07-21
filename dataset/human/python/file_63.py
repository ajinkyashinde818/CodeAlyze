def input_from_console():
    r, g, b, n = map(int, input().split())

    return r, g, b, n


def main():
    r, g, b, n = input_from_console()
    counter = 0
    r, g, b = sorted([r, g, b], reverse=True)
    for i1 in reversed(range(int(n / r) + 1)):
        n1 = n - r * i1
        for i2 in reversed(range(int(n1 / g) + 1)):
            n2 = n1 - g * i2
            if n2 % b == 0:
                counter += 1
    print(counter)


if __name__ == "__main__":
    main()
