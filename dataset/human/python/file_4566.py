import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    sys.setrecursionlimit(10**7)
    INF = 10**18
    MOD = 10**9 + 7
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())
    SI = lambda : sys.stdin.readline().rstrip()

    N = NI()
    d = {}
    for i in range(2,int(math.sqrt(N))+1):
        while N % i == 0:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
            N //= i
    if N > 1:
        d[N] = 1

    ans = 0
    for i in d.values():
        n = int((-1+math.sqrt(1+4*2*i))/2)
        ans += n
    print(ans)
if __name__ == '__main__':
    main()
