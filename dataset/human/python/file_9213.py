import sys
import math  # noqa
import bisect  # noqa
import queue  # noqa


def input():
    return sys.stdin.readline().rstrip()


if __name__ == '__main__':
    S = input()

    i = 0
    ans = False
    while True:
        res = S[i:i + 5]
        if res == "dream":
            i = i + 5
            if S[i:i + 5] == "dream":
                continue
            elif S[i:i + 7] == "erdream":
                i = i + 2
                continue
            elif S[i:i + 5] == "erase":
                continue
            elif S[i:i + 7] == "ererase":
                i = i + 2
                continue
            elif i == len(S):
                ans = True
                break
            elif i == len(S) - 2:
                if S[i:] == "er":
                    ans = True
                    break
                else:
                    ans = False
                    break
            else:
                ans = False
                break
        elif res == "erase":
            i = i + 5
            if S[i:i + 5] == "dream":
                continue
            elif S[i:i + 6] == "rdream":
                i = i + 1
                continue
            elif S[i:i + 5] == "erase":
                continue
            elif S[i:i + 6] == "rerase":
                i = i + 1
                continue
            elif i == len(S):
                ans = True
                break
            elif i == len(S) - 1:
                if S[i:] == "r":
                    ans = True
                    break
                else:
                    ans = False
                    break
            else:
                ans = False
                break

    if ans:
        print("YES")
    else:
        print("NO")
