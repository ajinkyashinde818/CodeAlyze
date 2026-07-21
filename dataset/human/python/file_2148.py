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
    [N] = [int(input_raw[0])]
    input_raw = read_func().strip().split()
    S = input_raw[0]
    dic = {}
    for s in S:
        if s not in dic:
            dic[s] = 1
        else:
            dic[s] += 1

    count = 1L
    for s in dic:
        count =  (count * long(dic[s] + 1)) % 1000000007L

    count = (count - 1) % 1000000007L
    print count


if __name__ == '__main__':
    main()
