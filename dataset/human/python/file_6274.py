import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    S = input().strip()

    ans = 0
    S_rev = S[::-1]
    kuriage = 0
    for i, s in enumerate(S_rev):
        if i == len(S) - 1:
            if int(s) == 9 and kuriage == 1:
                ans += 1
            elif int(s) + kuriage >= 6:
                ans += 10 - int(s) - kuriage + 1
            else:
                ans += int(s) + kuriage
        else:
            if int(s) == 9 and kuriage == 1:
                continue
            if int(s) + kuriage >= 6:
                ans += 10 - int(s) - kuriage
                kuriage = 1
            elif int(s) + kuriage == 5 and int(S_rev[i + 1]) >= 5:
                ans += 10 - int(s) - kuriage
                kuriage = 1
            else:
                ans += int(s) + kuriage
                kuriage = 0
    print(ans)


if __name__ == '__main__':
    main()
