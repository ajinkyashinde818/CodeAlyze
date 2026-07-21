def main():
    s = input()
    while s:
        if s[:7] == 'dreamer':
            if s[:10] != 'dreamerase':
                s = s[7:]
            else:
                s = s[5:]
        elif s[:5] == 'dream':
            s = s[5:]
        elif s[:6] == 'eraser':
            if s[:10] != 'eraseerase':
                s = s[6:]
            else:
                s = s[5:]
        elif s[:5] == 'erase':
            s = s[5:]
        else:
            return 'NO'
    else:
        return 'YES'





print(main())
