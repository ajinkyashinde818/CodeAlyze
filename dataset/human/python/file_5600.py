def main():
    s = input()
    n = len(s)
    l, r, ans = 0, n-1, 0
    while l < r:
        if s[l] == s[r]:
            l += 1
            r -= 1
        elif s[l] == "x":
            ans += 1
            l += 1
        elif s[r] == "x":
            r -= 1
            ans += 1
        else:
            print(-1)
            exit()
    print(ans)


if __name__ == "__main__":
    main()
