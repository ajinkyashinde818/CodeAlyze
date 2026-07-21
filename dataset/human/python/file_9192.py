import sys

S = input()

while S:
    prefix = S[0:5]
    if prefix == 'dream':
        if S[5:7] == 'er':
            if len(S) >= 8 and S[7] == 'a':
                S = S[5:]
            else:
                S = S[7:]
        else:
            S = S[5:]
    elif prefix == 'erase':
        if len(S) >= 6 and S[5] == 'r':
            S = S[6:]
        else:
            S = S[5:]
    else:
        print('NO')
        sys.exit(0)
    # print(S)
print('YES')
