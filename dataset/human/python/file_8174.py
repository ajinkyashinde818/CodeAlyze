import sys
input = sys.stdin.readline
from itertools import combinations

def main():
    k, s = map(int, input().split())
    for x in range(k+1):
        for y in range(k+1):
            z = s - x - y
            if 0 <= z <= k:
                yield 1

print(sum(main()))
