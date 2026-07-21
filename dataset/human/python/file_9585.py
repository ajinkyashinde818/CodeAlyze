import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    sys.setrecursionlimit(10**7)
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())

    N,K = LI()
    A = [0] + LI()

    his = [0] * (N+1)
    s = 1
    cnt = K

    while cnt > 0:
        his[s] = cnt
        s = A[s]
        cnt -= 1
        if his[s] > cnt:
            cnt = cnt % (his[s]-cnt)
    print(s)

if __name__ == '__main__':
    main()
