def solve():
    S = input()
    ['dream', 'dreamer', 'erase', 'eraser']
    r_S = S[::-1]
    while(len(r_S) > 0):
        if r_S[:7] == 'dreamer'[::-1]:
            r_S = r_S[7:]
        elif r_S[:6] == 'eraser'[::-1]:
            r_S = r_S[6:]
        elif r_S[:5] == 'dream'[::-1] or r_S[:5] == 'erase'[::-1]:
            r_S = r_S[5:]
        else:
            break
    if len(r_S) == 0:
        print('YES')
    else:
        print('NO')

solve()
