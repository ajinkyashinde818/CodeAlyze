import bisect
import math
from collections import deque

def sRaw():
    return input().rstrip("\r")


def iRaw():
    return int(input())


def ssRaw():
    return input().split()


def isRaw():
    return list(map(int, ssRaw()))

INF = 1 << 29



def main():
    K,N = isRaw()
    As = isRaw()
    ans = K-As[0]-(K-As[-1])
    for aidx in range(len(As)-1):
        ans = min(ans,K-(As[aidx+1]-As[aidx]))
    return ans

if __name__ == "__main__":
    print(main())
