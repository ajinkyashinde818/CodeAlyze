import sys
from collections import Counter

input = sys.stdin.readline
P = 10 ** 9 + 7


def main():
    N = int(input())
    S = input().rstrip()

    c = Counter(S)
    ans = 1
    for v in c.values():
        ans = (ans * (v + 1)) % P

    ans = (ans - 1) % P
    print(ans)


if __name__ == "__main__":
    main()
