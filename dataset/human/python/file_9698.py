import bisect
import collections
import heapq
import math
import operator as op
from collections import Counter
from functools import reduce

import numpy as np


def get_inputs(cast_func=None):
    if cast_func is None:
        return input().split()
    else:
        return list(map(cast_func, input().split()))


def get_input(cast_func=None):
    if cast_func is None:
        return input()
    else:
        return cast_func(input())


def main():

    N, K = get_inputs(int)
    As = get_inputs(int)
    As = [None, ] + As

    prev = 1
    history = {}
    history[1] = 0
    for n_teles in range(1, K+1):
        cur = As[prev]
        if cur in history:
            # Returned to start
            len_cyc = n_teles - history[cur]
            # print("len_cyc: ", len_cyc)
            # print("K - n_teles: ", K- n_teles)
            for _ in range((K - n_teles) % len_cyc):
                cur = As[cur]
            print(cur)
            return
        else:
            prev = cur
            history[cur] = n_teles
    print(cur)

# def main():
#     N, M, X = get_inputs(int)
#     Cs = np.empty(N, dtype=np.int)
#     A_mat = np.empty((N, M), dtype=np.int)
#     for i in range(N):
#         CAs = get_inputs(int)
#         Cs[i] = CAs[0]
#         for j in range(M):
#             A_mat[i, j] = CAs[j+1]

#     if (np.sum(A_mat, axis=0) >= X).all():
#         ans = float("inf")


#     else:
#         print(-1)


#     # N, M, X = get_inputs()
#     # CAs_arr = []
#     # for _ in range(N):
#     #     CAs = get_inputs(int)
#     #     CAs_arr.append(CAs)

#     # Sums = [0 for _ in range(M)]
#     # for i in range(M):
#     #     for j in range(N):
#     #         Sums[i] += CAs_arr[j][i+1]

#     # if all([Sum >= X for Sum in Sums]):
#     #     pass
#     # else:
#     #     print(-1)


if __name__ == '__main__':
    main()
