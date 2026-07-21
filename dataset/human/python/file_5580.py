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
    [S] = [(input_raw[0])]
    head = 0
    tail = len(S) - 1
    count = 0
    #for i in range(len(S)/2 + len(S) % 2):
    while 1:
        if head >= tail:
            break
        if S[head] != S[tail]:
            if S[head] == "x":
                count += 1
                head += 1
            elif S[tail] == "x":
                count += 1
                tail -= 1
            else:
                print -1
                return
        else:
            head += 1
            tail -= 1
    print count


if __name__ == '__main__':
    main()
