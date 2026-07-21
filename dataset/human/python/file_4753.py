import sys


def main():
    s = sorted(input())
    t = sorted(input())[::-1]

    for i, j in zip(s, t):
        if i == j:
            continue
        else:
            if ord(i) > ord(j):
                print('No')
                sys.exit(0)
            else:
                print('Yes')
                sys.exit(0)

    if len(s) < len(t):
        print('Yes')
    else:
        print('No')


if __name__ == "__main__":
    main()
