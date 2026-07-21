def resolve():
    S = input()
    Q = int(input())

    from collections import deque
    strings = deque([S])
    switch = 0
    for _ in range(Q):
        line = input()
        if line.startswith('1'):
            switch ^= 1
            continue
        _, n, char = line.split()
        if n == '1':
            if switch == 0:
                strings.appendleft(char)
            else:
                strings.append(char)
        else:
            if switch == 0:
                strings.append(char)
            else:
                strings.appendleft(char)

    if switch:
        print(''.join(strings)[::-1])
    else:
        print(''.join(strings))
resolve()
