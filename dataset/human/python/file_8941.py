import sys
s = str(input())
ls = ["dream","dreamer","erase","eraser"]
while True:
    k = s[-5:]
    if k not in ls:
        t = s[-6:]
        if t not in ls:
            l = s[-7:]
            if l not in ls:
                print("NO")
                sys.exit()
            else:
                s = s[:-7]
                if s == "":
                    print("YES")
                    break
        else:
            s = s[:-6]
            if s == "":
                print("YES")
                break
    else:
        s = s[:-5]
        if s == "":
            print("YES")
            break
