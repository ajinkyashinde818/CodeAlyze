from sys import stdin


def main():
    s, t = [stdin.readline().rstrip() for _ in range(2)]
    s = ''.join(sorted(s))
    t = ''.join(sorted(t, reverse=True))
    print('Yes' if s < t else 'No')


if __name__ == "__main__":
    main()
