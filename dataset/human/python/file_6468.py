import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque, Counter
def getN():
    return int(input())
def getList():
    return list(map(int, input().split()))
import math

def main():
    n = getN()
    parity = n % 2
    if parity == 1:
        print(0)
        return
    ans = 0

    tmp = 5
    while(tmp <= n):
        rep = n // tmp
        ans += (rep + parity) // 2
        tmp *= 5

    print(ans)

if __name__ == "__main__":
    main()
