def main():
    s = input()
    chars = list(s)
    length = len(s)
    l = 0
    r = length - 1
    xcount = 0
    while l <= r and 0 <= r and l < length:
        if chars[l] == chars[r]:
            l += 1
            r -= 1
            continue

        if chars[l] == 'x':
            xcount += 1
            l += 1
            continue

        if chars[r] == 'x':
            xcount += 1
            r -= 1
            continue
        print(-1)
        return

    print(xcount)


main()
