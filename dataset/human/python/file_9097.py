import sys

S = input()

while S:
    if S[-1] == 'r':
        if S[-7:] == 'dreamer':
            S = S[:-7]
        elif S[-6:] == 'eraser':
            S = S[:-6]
        else:
            print('NO')
            sys.exit()
    elif S[-5:] == 'dream' or S[-5:] == 'erase':
        S = S[:-5]
    else:
        print('NO')
        sys.exit()

print('YES')
