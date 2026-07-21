if __name__ == '__main__':
    L = ['dream', 'dreamer', 'erase', 'eraser']
    S = input()
    n = len(S)

    while True:
        if S[-7:] == 'dreamer':
            n -= 7
            S = S[:-7]
        elif S[-6:] == 'eraser':
            n -= 6
            S = S[:-6]
        elif S[-5:] == 'dream' or S[-5:] == 'erase':
            n -= 5
            S = S[:-5]
        else:
            break
    if len(S) == 0:
        print('YES')
    else:
        print('NO')
