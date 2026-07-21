def solution():
    s = input()
    T = ['dreamer', 'dream', 'eraser', 'erase']

    while True:
        match = False
        for ss in T:
            if s.endswith(ss) :
                s = s[:-1*len(ss)]
                if not s:
                    print('YES')
                    return
                match = True
                break
        if not match:
            print('NO')
            return

solution()
