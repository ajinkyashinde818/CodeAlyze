import sys
IS = lambda: sys.stdin.readline().rstrip()
II = lambda: int(IS())
MII = lambda: list(map(int, IS().split()))

def main():
    s = IS()
    if 'a' in s and 'b' in s and 'c' in s: print('Yes')
    else: print('No')

if __name__ == '__main__':
    main()
