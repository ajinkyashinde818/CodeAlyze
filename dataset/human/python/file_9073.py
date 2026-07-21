import sys
S = input()[::-1]

length = len(S)
i = 0

while i < length:
    if S[i:i+5] == 'dream'[::-1]:
        i += 5
    elif S[i:i+7] == 'dreamer'[::-1]:
        i += 7
    elif S[i:i+5] == 'erase'[::-1]:
        i += 5
    elif S[i:i+6] == 'eraser'[::-1]:
        i += 6
    else:
        print('NO')
        sys.exit()
    
print('YES')
