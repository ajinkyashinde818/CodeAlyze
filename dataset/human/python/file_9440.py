"""    Arnab Chanda    """

from collections import defaultdict, deque
from itertools import permutations
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
from copy import deepcopy
import heapq

int_input=lambda : int(stdin.readline())
string_input=lambda : stdin.readline().split()
multi_int_input =lambda : map(int, stdin.readline().split())
multi_input = lambda : stdin.readline().split()
list_input=lambda : list(map(int,stdin.readline().split()))
string_list_input=lambda: list(string_input())
MOD = pow(10,9)+7


n, k = multi_int_input()

a = list_input()


prev = 1

if k < n:
    
    for i in range(k):
        nextTown = a[prev-1]
        prev = nextTown

    print(prev)

else:

    seti = {}
    seti[1] = 0
    count = 0
    cycle = 0
    x = 0
    order = [1]
    while(True):
        count+=1
        nextTown = a[prev-1]
        order.append(nextTown)
        prev = nextTown
        if nextTown in seti:
            cycle = count - seti[nextTown]
            x = seti[nextTown]
            break
        else:
            seti[nextTown] = count

    # print(k, cycle, x, seti)
    k = k - (x - seti[1])
    # print(k, order)
    print(order[x+(k%cycle)])
