import sys

s = input()

while len(s) != 0:
    if s.endswith('dream') or s.endswith('erase'):
        s = s[:-5]
    elif s.endswith('eraser'):
        s = s[:-6]
    elif s.endswith('dreamer'):
        s = s[:-7]
    else:
        print('NO')
        sys.exit()

print('YES')
