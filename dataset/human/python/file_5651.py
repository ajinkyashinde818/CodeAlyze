def main():
    s = input().rstrip()
    ans = 0
    f = True
    l, r = 0, len(s)-1
    while l < r:
        if s[l] != s[r]:
            if s[l] != "x" and s[r] != "x":
                f = False
                break
            elif s[l] == "x":
                ans += 1
                l += 1
            else:
                ans += 1
                r -= 1
        else:
            l += 1
            r -= 1
    if f:
        print(ans)
    else:
        print("-1")

if __name__ == "__main__":
    main()
