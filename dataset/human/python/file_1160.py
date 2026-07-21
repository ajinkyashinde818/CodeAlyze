import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())

    N = NI()
    A = LI()
    B = LI()

    c = collections.Counter()
    for x in A:
        c[x] += 1
    for x in B:
        c[x] += 1
        if c[x] > N:
            print('No')
            return

    s = 0
    for i in range(N):
        if A[i] == B[i]:

            p = bisect.bisect_left(B,B[i]+1,i+1)
            if p > N-1:
                p = s
                s += 1
                while B[i] == B[s]:
                    s+=1

            B[i],B[p] = B[p],B[i]
    print('Yes')
    print(*B,sep=' ')

if __name__ == '__main__':
    main()
