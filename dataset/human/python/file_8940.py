def main():
    s = input()
    w = ["dream", "dreamer", "erase", "eraser"]
    last = len(s)
    for _ in range(len(s)):
        if last < 1:
            break
        for ww in w:
            if s[last - len(ww):] == ww:
                s = s[:last - len(ww)]
                last -= len(ww)
    print("YES" if last < 1 else "NO")


if __name__ == '__main__':
    main()
