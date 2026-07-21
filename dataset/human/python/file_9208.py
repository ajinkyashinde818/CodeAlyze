import sys

input = sys.stdin.readline


def main():
    S = input().rstrip()

    S = S[::-1]
    idx = 0
    ans = "YES"
    while idx <= len(S) - 1:
        is_ok = False
        if S[idx:idx + 5] in ("maerd", "esare"):
            is_ok = True
            idx += 5
        if S[idx:idx + 6] == "resare":
            is_ok = True
            idx += 6
        if S[idx:idx + 7] == "remaerd":
            is_ok = True
            idx += 7

        if not is_ok:
            ans = "NO"
            break

    print(ans)


if __name__ == "__main__":
    main()
