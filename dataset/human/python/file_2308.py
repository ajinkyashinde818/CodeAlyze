import sys
from bisect import *
from collections import *
from copy import deepcopy
from heapq import *
from itertools import *
from math import *
from operator import *
import numpy as np

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

def main():
    """ main """
    D,G = map(int, input().split())
    qs = [list(map(int, input().split())) for _ in range(D)]
    q_totals = [100*(i+1)*q[0]+q[1] for i,q in enumerate(qs)]

    ans = float('inf')
    for bit in range(1<<D):
        total = 0
        target_qs = []
        another_q_idx = 0
        for i in range(D):
            if bit & 1<<i:
                total += q_totals[i]
                target_qs.append(qs[i])
            else:
                another_q_idx = i
        tmp_ans = sum([q[0] for q in target_qs])

        if total < G and G <= total + 100*(another_q_idx+1)*(qs[another_q_idx][0]-1):
            tmp_ans += ceil((G-total)/(100*(another_q_idx+1)))
        elif total + 100*(another_q_idx+1)*(qs[another_q_idx][0]-1) < G:
            tmp_ans = float('inf')

        ans = min(ans, tmp_ans)
    print(ans)


if __name__ == '__main__':
    main()
