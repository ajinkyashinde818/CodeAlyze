import numpy
from operator import add
from functools import reduce

N = int(input())
A = list(map(int, input().split()))

minus_num = 0
abs_A = []
for a in A:
    if a < 0:
        minus_num += 1
    abs_A.append(numpy.abs(a))

if minus_num % 2 == 0:
    print(reduce(add, abs_A))
else:
    abs_A.sort()
    print(reduce(add, abs_A[1:])-abs_A[0])
