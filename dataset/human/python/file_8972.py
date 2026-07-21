import sys
S = input()
S = S[::-1]
while S != '':
    if S[:5] == 'maerd':
        S = S[5:]
    elif S[:5] == 'esare':
        S = S[5:]
    elif S[:6] == 'resare':
        S = S[6:]
    elif S[:7] == 'remaerd':
        S = S[7:]
    else:
        print('NO')
        exit()
print('YES')
