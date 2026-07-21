import copy
import sys
import numpy as np

from math import *
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
    [N] = [int(input_raw[0])]
    if int(N/10) == 9 or int(N % 10) == 9:
        print "Yes"
    else:
        print "No"

if __name__ == '__main__':
    main()
