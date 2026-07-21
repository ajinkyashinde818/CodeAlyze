import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    sys.setrecursionlimit(10**7)
    INF = 10**18
    MOD = 10**9 + 7
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())

    D,G = LI()
    pc = [LI() for _ in range(D)]
    m = [i for i in range(D)]
    ans = INF
    for p in itertools.permutations(m):
        g = G
        cnt = 0
        for i in p:
            if g < pc[i][0] * (i+1) * 100:
                cnt += math.ceil(g/((i+1)*100))
                break
            else:
                cnt += pc[i][0]
                g -= pc[i][0] * (i+1) * 100 + pc[i][1]
            if g <= 0: break
        ans = min(ans,cnt)

    print(ans)


if __name__ == '__main__':
    main()
