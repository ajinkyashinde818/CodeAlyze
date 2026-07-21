'''
.append(要素) リストに要素を追加
.extend(リスト) リストを連結する
.insert(場所,要素) 指定した場所に要素追加
del 配列名[場所]
-1で末尾で末尾から一つ前

sort()
sorted(reverse=true)

配列の初期化
配列名=[a]*n+[b]*m

Decimal()
'''

from sys import stdin
from itertools import accumulate, dropwhile, takewhile, groupby
import bisect
import copy
import math
from functools import reduce
from operator import mul
from collections import Counter
import itertools


a = [int(s) for s in stdin.readline().rstrip().split()]
K = a[0]
N = a[1]
A = [int(s) for s in stdin.readline().rstrip().split()]

diff = []
for el in range(len(A)):
    if el == len(A) - 1:
        diff.append(K-A[el]+A[0])
        break
    diff.append(A[el+1]-A[el])

print(K-max(diff))
