import sys
S = input()
S = S[::-1]
f = 1

while f > 0 and len(S)>0:
    if S.find('maerd') ==0 or S.find('esare') == 0:
        S = S[5:]
    elif S.find('remaerd') == 0:
        S = S[7:]
    elif S.find('resare') == 0:
        S = S[6:]
    else:
        f = -1

if f > 0:
    print('YES')
else:
    print('NO')
