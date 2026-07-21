from collections import defaultdict
from collections import deque
from string import ascii_uppercase
import sys, bisect, math, heapq

stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

N, R = read_int()

def solve():
    ans = 0
    if N >= 10:
        return R
    return R + 100 * (10 - N)

if __name__ == "__main__":
    print(solve())
