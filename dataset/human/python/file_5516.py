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
    a = [str(i) for i in input().split()]

    if ord(a[0]) > ord(a[1]):
        print(">")
    elif ord(a[0]) < ord(a[1]):
        print("<")
    else:
        print("=")
