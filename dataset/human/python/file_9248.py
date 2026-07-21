def main():
    s = str(input())
    while(len(s) != 0):
        if s[-6:] == "eraser":
            s = s[:-6]
            continue
        elif s[-7:] == "dreamer":
            s = s[:-7]
            continue
        elif s[-5:] == "erase":
            s = s[:-5]
            continue
        elif s[-5:] == "dream":
            s = s[:-5]
            continue
        else:
            return print("NO")
    print("YES")
    


if __name__ == '__main__':
    main()
