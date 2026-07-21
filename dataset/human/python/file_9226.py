import re
import sys
s = input()
while True:
    if s[-5:] in ['dream', 'erase']:
        s = s[0:-5]
    elif s[-6:] in ['eraser']:
        s = s[0:-6]
    elif s[-7:] in ['dreamer']:
        s = s[0:-7]
    else:
        if s == '':
            print('YES')
            sys.exit()
        else:
            print("NO")
            sys.exit()
