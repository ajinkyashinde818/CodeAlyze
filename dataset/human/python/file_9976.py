import sys 
from math import gcd
from functools import reduce
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
A, B = map(int, readline().split())
AB = []
AB.append(A)
AB.append(B)
lcm = reduce(lambda x,y:x*y//gcd(x,y),AB)
print(lcm)
