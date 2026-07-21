import sys
import math
import bisect
import re

def solve():
    s = input()
    t = input()
    s = ''.join(sorted(s))
    t = ''.join(sorted(t, reverse=True))
    return s < t

def main():
    if solve():
        print('Yes')
    else:
        print('No')

if __name__ == "__main__":
    main()
