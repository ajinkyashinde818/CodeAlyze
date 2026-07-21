def main():
    S = input()
    N = len(S)
    ok = set(['dream','erase','dreamer','eraser'])
    if N < 8 and S not in ok:
        print("NO")
        exit()
    i = 0
    while i < N-5:
        tmp = S[i:i+5]
        if tmp == 'dream':
            if i+6 < N and S[i+5:i+7] == 'er':
                if i+7<N and S[i+7] == 'a':
                    i += 5
                else:
                    i += 7
            else:
                i += 5
        elif tmp == 'erase':
            if i+5<N and S[i+5] == 'r':
                i += 6
            else:
                i += 5
        else:
            print('NO')
            exit()
    if i < N and S[i:] not in ok:
        print('NO')
        exit()
    print('YES')

if __name__ == "__main__":
    main()
