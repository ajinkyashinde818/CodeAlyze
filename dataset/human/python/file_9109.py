import sys
s = input()
i = 0
while s[i:i+5] != '':
    if s[i:i+5] == 'dream':
        if s[i+5:i+10] == 'dream':
            i += 5
        elif s[i+5:i+10] == 'erase':
            i += 5
        elif s[i+5:i+7] == 'er':
            i += 7
        else:
            i += 5
    elif s[i:i+5] == 'erase':
        if s[i+5:i+10] == 'dream':
            i += 5
        elif s[i+5:i+10] == 'erase':
            i += 5
        elif s[i+5:i+6] == 'r':
            i += 6
        else:
            i += 5
    else:
        print('NO')
        sys.exit(0)
print('YES')
