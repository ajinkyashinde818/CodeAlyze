import sys
import math
import numpy
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)
 
p = int(readline())
if p % 2 == 1:
    print(0)
else:
    p //= 2
    ans = 0
    while p:
        p //= 5
        ans += p
    print(ans)
