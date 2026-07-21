import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def main():
    S = read().decode('utf-8')
    S = list(S.replace('\n', ''))[::-1]
    T = [
            list('dream')[::-1],
            list('dreamer')[::-1],
            list('erase')[::-1],
            list('eraser')[::-1]
        ]

    while len(S) != 0:
        if S[0:5] == T[0] or S[0:5] == T[2]:
            del S[0:5]
        elif S[0:7] == T[1]:
            del S[0:7]
        elif S[0:6] == T[3]:
            del S[0:6]
        else:
            print('NO')
            sys.exit()

    print('YES')


main()
