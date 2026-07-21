import sys
from collections import deque, Counter, defaultdict
from fractions import gcd
input = lambda: sys.stdin.readline().rstrip()

def eprint(s):
    sys.stderr.write('DEBUG: {}'.format(s))
    return

def main():
    n, r = map(int, input().split())
    if n>= 10:
        print(r)
    else:
        # r = 100 * (10-n)
        print(r+ 100*(10-n))
    return

if __name__ == '__main__':
    main()
