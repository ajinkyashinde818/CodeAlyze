from sys import stdin
from sys import setrecursionlimit
from collections import Counter, deque, defaultdict
from math import floor, ceil
from bisect import bisect_left
from itertools import combinations
setrecursionlimit(100000)

INF = int(1e10)
MOD = int(1e9 + 7)

def factorization(n):
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

def main():
    from builtins import int, map
    n = int(input())
    if n == 1:
        print(0)
        exit()

    fn = factorization(n)
    cmax = max([f[1] for f in fn])
    z = set({})

    k = 1
    flag_get = True
    while flag_get and k <= cmax:
        flag = False
        for i in range(len(fn)):
            pi, ni = fn[i]
            if ni >= k:
                flag = True
                z.add(pi ** k)
                fn[i][1] -= k
        if not flag:
            break
        k += 1
    print(len(z))

if __name__ == '__main__':
    main()
