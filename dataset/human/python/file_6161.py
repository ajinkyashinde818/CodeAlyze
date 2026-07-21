import sys
from collections import deque
import copy
import math
def get_read_func(fileobject):
    if fileobject == None :
        return raw_input
    else:
        return fileobject.readline

def main():
    if len(sys.argv) > 1:
        f = open(sys.argv[1])
    else:
        f = None
    read_func = get_read_func(f);
    input_raw = read_func().strip().split()
    [A, B, C] = [int(input_raw[0]), int(input_raw[1]), int(input_raw[2])]
    posC = min(C, (A + B) + 1)
    print posC + B

if __name__ == '__main__':
    main()
