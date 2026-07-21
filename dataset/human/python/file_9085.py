import sys
s=input()
i=len(s)-1
while True:
    if i<0:
        print('YES')
        sys.exit()
    if i>=4:
        if s[i-4:i+1]=='dream':
            i-=5
            continue
        elif s[i-4:i+1]=='erase':
            i-=5
            continue
    if i>=5 and s[i-5:i+1]=='eraser':
        i-=6
        continue
    if i>=6 and s[i-6:i+1]=='dreamer':
        i-=7
        continue
    print('NO')
    sys.exit()
