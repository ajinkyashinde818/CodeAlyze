def main():
    S = input()
    while len(S):
        if S[:7] == 'dreamer':
            if S[5:11] == 'eraser':
                S = S[5:]
            elif S[5:10] == 'erase':
                S = S[5:]
            else:
                S = S[7:]
        elif S[:5] == 'dream':
            S = S[5:]
        elif S[:6] == 'eraser':
            S = S[6:]
        elif S[:5] == 'erase':
            S = S[5:]
        else:
            print('NO')
            exit()
    print('YES')


if __name__ == '__main__':
    main()
