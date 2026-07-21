import sys

def solve():
    x = int(input())

    if x < 1200:
        print('ABC')
    else:
        print('ARC')
    

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None


if __name__ == '__main__':
    solve()
