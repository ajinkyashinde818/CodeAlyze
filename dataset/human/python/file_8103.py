from sys import stdin


def main():
    k = next_int()
    s = next_int()
    ans = 0
    for x in range(k + 1):
        for y in range(k + 1):
            z = s - x - y
            if 0 <= z <= k:
                ans += 1
    print(ans)


def next_int() -> int:
    return int(next_str())


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
