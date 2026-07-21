import sys

sys.setrecursionlimit(1000000)
S = input()


def start_with(i):
    if i == len(S):
        print('YES')
        sys.exit(0)

    try:
        if S[i:i+5] == 'dream':
            start_with(i+5)
        if S[i:i+7] == 'dreamer':
            start_with(i+7)
        if S[i:i+5] == 'erase':
            start_with(i+5)
        if S[i:i+6] == 'eraser':
            start_with(i+6)
        return
    except IndexError:
        return


start_with(0)
print('NO')
