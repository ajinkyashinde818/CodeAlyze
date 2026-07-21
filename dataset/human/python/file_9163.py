import sys
S = str(input())
while S != '':
    if (S[:5] == 'dream' and S[5:11] == 'eraser') or (S[:5] == 'dream' and S[5: 10] == 'erase') or (S[:5] == 'dream' and S[5:] == '') or (S[:5] == 'dream' and S[5:10] == 'dream'):
        S = S[5:]
    elif (S[:5] == 'erase' and S[5:] != '' and S[5] != 'r') or (S[:5] == 'erase' and S[5:] == ''):
        S = S[5:]
    elif S[:6] == 'eraser':
        S = S[6:]
    elif S[:7] == 'dreamer':
        S = S[7:]
    else:
        print('NO')
        sys.exit()
        break
        
print('YES')
