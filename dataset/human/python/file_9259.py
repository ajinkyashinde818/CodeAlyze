import sys
sys.setrecursionlimit(100000000)

S = input()[::-1]


while len(S) > 0:
    if S[0] == 'r':
        if S[0:6] == 'resare':
            S = S[6:]
        elif S[0:7] == 'remaerd':
            S = S[7:]
        else:
            print('NO')
            exit()
    elif S[0:5] == 'maerd':
        S = S[5:]
    elif S[0:5] == 'esare':
        S = S[5:]
    else:
        print('NO')
        exit()
print('YES')
