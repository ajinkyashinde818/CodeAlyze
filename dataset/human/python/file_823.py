import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque, Counter
def getN():
    return int(input())
def getList():
    return list(map(int, input().split()))
import math
INF = 10 ** 20

def main():
    a,b = getList()
    if a >= 10:
        print(b)
    else:
        print(b + 100*(10-a))

if __name__ == "__main__":
    main()
