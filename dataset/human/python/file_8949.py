def main():
    S = input()
    S = S[::-1]
    _T = 'dreamer', 'dream', 'eraser', 'erase'
    T = []
    for t in _T:
        T.append(t[::-1])
    i = 0
    while 1:
        temp = []
        bool = True
        for t in T:
            if S[:len(t)] == t:
                S = S[len(t):]
                bool = False
        if bool:
            break
    if len(S) > 0:
        print('NO')
    else:
        print('YES')


if __name__ == '__main__':
    main()
