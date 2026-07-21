def ans2():
    s = input()
    flag = True
    while flag:
        if (s[-7:])=='dreamer':
            s = s[:-7]
        elif (s[-5:])=='dream':
            s = s[:-5]
        elif (s[-6:])=='eraser':
            s = s[:-6]
        elif (s[-5:])=='erase':
            s = s[:-5]
        else:
            flag = False
    
    if not s:
        print("YES")
    else:
        print("NO")
ans2()
