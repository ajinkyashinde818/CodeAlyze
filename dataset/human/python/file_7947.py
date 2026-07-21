import sys
import copy
import math
import bisect
import pprint
import bisect
from functools import reduce
from copy import deepcopy
from collections import deque

if __name__ == '__main__':
    a = input()
    b = []
    for i in a:
        b.append(i)

    aset = set(b)

    if len(aset) ==3:
        print("Yes")
    else:
        print("No")
