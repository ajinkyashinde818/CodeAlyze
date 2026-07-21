def main():
    s = input()
    while len(s) > 0:
        if s[-7:] == "dreamer":
            s = s[:-7]
        elif s[-6:] == "eraser":
            s = s[:-6]
        elif s[-5:] == "dream":
            s = s[:-5]
        elif s[-5:] == "erase":
            s = s[:-5]
        else:
            print("NO")
            break
    else:
        print("YES")


if __name__ == '__main__':
    main()
