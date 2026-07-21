''' Hey stalker :) '''
INF = 10**10
def main():
    print = out.append
    ''' Cook your dish here! '''
    n, k, s = get_list()
    junk = 10**9 if s!=10**9 else 10**9 - 1
    res = [s]*k + [junk]*(n-k)
    print(" ".join(map(str, res)))


''' Pythonista fLite 1.1 '''
import sys
from collections import defaultdict, Counter
from bisect import bisect_left, bisect_right
#from functools import reduce
#import math
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
out = []
get_int = lambda: int(input())
get_list = lambda: list(map(int, input().split()))
main()
#[main() for _ in range(int(input()))]
print(*out, sep='\n')
