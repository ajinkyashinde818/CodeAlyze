import sys

input = sys.stdin.readline


def main():
    S = input().rstrip()

    i = 0
    x_cnt = [0]
    T = ""
    for s in S:
        if s == "x":
            x_cnt[i] += 1
        else:
            T = "".join((T, s))
            i += 1
            x_cnt.append(0)

    is_palindrome = True
    for i in range(len(T) // 2):
        if T[i] != T[-(i+1)]:
            is_palindrome = False

    if is_palindrome:
        ans = 0
        for i in range(len(x_cnt) // 2):
            ans += abs(x_cnt[i] - x_cnt[-(i+1)])
    else:
        ans = -1
    print(ans)


if __name__ == "__main__":
    main()
