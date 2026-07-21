import sys
def input(): return sys.stdin.readline().strip()

def main():
    s = input()
    l = len(s)
    while s:
        if s[-5:] == "dream":
            s = s[:-5]
        elif s[-7:] == "dreamer":
            s = s[:-7]
        elif s[-5:] == "erase":
            s = s[:-5]
        elif s[-6:] == "eraser":
            s = s[:-6]
        else:
            print("NO")
            return
    print("YES")



if __name__ == "__main__":
    main()
