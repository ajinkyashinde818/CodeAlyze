if __name__ == "__main__":
    s = input()
    words = ["dream", "dreamer", "erase", "eraser"]
    while len(s) > 0:
        if s[-5:] in ["dream", "erase"]:
            s = s[:-5]
        elif s[-7:] == "dreamer":
            s = s[:-7]
        elif s[-6:] == "eraser":
            s = s[:-6]
        else:
            print("NO")
            break
    if not len(s):
        print("YES")
