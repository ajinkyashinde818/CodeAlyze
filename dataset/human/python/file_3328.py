import math
from math import gcd
INF = float("inf")

import sys
input=sys.stdin.readline
import itertools
from collections import Counter

def main():
    def factorization(n):
        if n == 1:
            return []
        arr = []
        temp = n
        for i in range(2, int(-(-n**0.5//1))+1):
            if temp%i==0:
                cnt=0
                while temp%i==0:
                    cnt+=1
                    temp //= i
                arr.append([i, cnt])

        if temp!=1:
            arr.append([temp, 1])

        if arr==[]:
            arr.append([n, 1])

        return arr
    m = [0]
    for i in range(1,10**6):
        m.append(m[i-1]+i)
    ans = 0

    n = int(input())
    k = factorization(n)
    for i,l in k:
        for u in range(len(m)):
            if l < m[u]:
                ans += u-1
                break
    print(ans)



if __name__=="__main__":
    main()
