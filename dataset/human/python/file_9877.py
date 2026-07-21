from sys import stdin
import math
import fractions
from collections import deque
from collections import Counter
import itertools

INF = 10 ** 10

N, K  = [int(x) for x in stdin.readline().rstrip().split()]
A = [0] + [int(x) for x in stdin.readline().rstrip().split()]

stack = [1]
nextt = A[1]
visited_dict = {1: True}

while True:
    if not visited_dict.get(nextt, False):
        stack.append(nextt)
        visited_dict[nextt] = True
    else:
        stack.append(nextt)
        break
    nextt = A[nextt]

    if len(stack) > K:
        print(stack[K])
        exit()

num1 = stack.pop()
length = len(stack)
tmp = []
while True:
    num2 = stack.pop()
    if num1 != num2:
        tmp.append(num2)
    else:
        tmp.append(num2)
        break

tmp = tmp[::-1]

index = (K - length) % len(tmp)

print(tmp[index])
