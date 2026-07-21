from sys import stdin


def main() -> None:
    s, t = [next_str() for _ in range(2)]
    print("Yes" if sorted(s) < (sorted(t, reverse=True)) else "No")


def next_str() -> str:
    result = ""
    while True:
        tmp = stdin.read(1)
        if tmp.strip() != "":
            result += tmp
        elif tmp != '\r':
            break
    return result


if __name__ == '__main__':
    main()
