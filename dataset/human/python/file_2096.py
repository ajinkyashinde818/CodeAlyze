from collections import Counter
from functools import reduce


def main():
    n = int(input())
    s = input()

    c = Counter(s)
    ans = reduce(lambda x, y: x * y, map(lambda x: x + 1, c.values())) - 1
    print(ans % (10**9+7))


if __name__ == "__main__":
    main()
