def main():
    s = input()
    t = s.replace("x", "")
    M = len(t)
    for i in range(M//2):
        if t[i] != t[M-i-1]:
            print(-1)
            return
    xcnt = [0] * (M+1)
    i = 0
    for c in s:
        if c == "x":
            xcnt[i] += 1
        else:
            i += 1
    ans = 0
    for i in range((M+1)//2):
        ans += abs(xcnt[i] - xcnt[M-i])
    print(ans)


if __name__ == "__main__":
    main()
