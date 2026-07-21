import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    sys.setrecursionlimit(10**7)
    INF = 10**18
    MOD = 10**9 + 7
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    _LI = lambda : [int(x)-1 for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())
    SI = lambda : sys.stdin.readline().rstrip()

    N = [0] + list(map(int,SI()))
    ans = 0
    for i in range(len(N)-1,-1,-1):

        if N[i] < 6 and not(N[i] == 5 and (i > 0 and N[i-1] >= 5)):
            ans += N[i]
        else:
            ans += 10 - N[i]
            N[i-1] += 1
    print(ans)
if __name__ == '__main__':
    main()
