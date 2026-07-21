from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpl_str(): return list(input().split())


while True:
    N = inp()
    if N == 0:
        break
    else:
        tt = [[' ']*1100 for _ in range(N)]
        LL = [0]*N
        SS = ['']*N
        bL = 1000

        for i in range(N):
            S = input()
            L = S.count('.')
            LL[i] = L
            SS[i] = S[L:]
            tt[i][L] = '+'
            if L < bL:
                for j in reversed(range(i)):
                    if LL[j] == L:
                        break
                    else:
                        tt[j][L] = '|'
            bL = L

        print(SS[0])
        for i in range(1,N):
            tmp = ''
            for j in range(1,1100):
                if tt[i][j]!='+':
                    tmp = tmp + tt[i][j]
                else:
                    tmp = tmp + '+' + SS[i]
                    break
            print(tmp)
