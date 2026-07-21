import sys
from collections import deque
import copy

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
    [N] = [long(input_raw[0])]

    if N==1:
        print "Yes"
        print 2
        print 1, 1
        print 1, 1
        exit()
    x = 3
    idx = 1
    accept_set = set([x])
    is_accept = False
    while x <= N:
        if N == x:
            is_accept = True
            break
        x += (idx + 2)
        accept_set.add(x)
        idx += 1

    
    if is_accept == False:
        print "No"
        exit()


    base = idx + 1
    row_num = base + 1
    col_num = base

    res = [[0 for i in range(col_num)] for j in range(row_num)]
    count = 1
    for i in range(row_num):
        for j in range(i, col_num):
            res[i][j] = count
            count += 1
        for k in range(col_num - i):
            res[i + k + 1][i] = res[i][k + i]

    print "Yes"
    print base + 1
    for i in range(row_num):
        print base,
        for j in range(col_num):
            print res[i][j],
        print
        




if __name__ == '__main__':
    main()
