import sys

input = sys.stdin.readline


def main():
    s = input().rstrip()
    t = input().rstrip()

    ss = "".join(sorted(s))
    tt = "".join(sorted(t, reverse=True))

    ans = "Yes" if ss < tt else "No"
    print(ans)


if __name__ == "__main__":
    main()
