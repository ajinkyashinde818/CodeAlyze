import sys
sys.setrecursionlimit(100000)


def ins(): return input().split()
def ii(): return int(input())
def iil(): return list(map(int, ins()))
def lin(): return list(input())
def iin(): return map(int, ins())

from collections import defaultdict
from math import sqrt

arr = []
max_p = int(500000)
l1 = [1 for i in range(max_p)]
l2 = set()
l2.add(2)
for i in range(max_p):
    if not l1[i]:
        continue
    l2.add(2*i+3)
    for j in range(3*i+3, max_p, 2*i+3):
        l1[j] = 0

n = int(input())
#n = 10 ** 12
dic = defaultdict(int)
for i in l2:
    while n % i == 0:
        n //= i
        dic[i] += 1
if n != 1:
    dic[n] += 1

ans = 0
for i in dic.values():
    ans += (-1 + sqrt(1 + 8 * i))//2
print(int(ans))
