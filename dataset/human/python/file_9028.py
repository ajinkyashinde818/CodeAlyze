import sys

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

def solve():
    S = input()
    pos = len(S)

    while pos > 0:
        if S[pos - 5:pos] == 'dream' or S[pos - 5:pos] == 'erase':
            pos -= 5
        elif S[pos - 7:pos] == 'dreamer':
            pos -= 7
        elif S[pos - 6:pos] == 'eraser':
            pos -= 6
        else:
            print('NO')
            return None

    print('YES')


if __name__ == '__main__':
    solve()
