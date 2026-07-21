import sys
import math
import numpy as np
import copy

def main():
    s = input()

    a, b, c, d = "dream", "dreamer", "erase", "eraser"
    ra, rb, rc, rd = a[::-1], b[::-1], c[::-1], d[::-1]
    rs = s[::-1]

    while rs:
        flag = False
        for ele in [ra, rb, rc, rd]:
            if rs.startswith(ele):
                rs = rs.replace(ele, "", 1)
                flag = True
        if not flag:
            print("NO")
            return 0
    
    print("YES")
    return 0

if __name__ == '__main__':
    sys.exit(main())
