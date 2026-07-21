def main():
    import sys
    sys.setrecursionlimit(10**6)
    input = sys.stdin.readline
    N, K = [int(x) for x in input().strip().split()]
    A = {i:int(x) for i, x in enumerate(input().strip().split(), start=1)}
    dic = {}
    p = 1
    cnt = 0
    dic[p] = cnt
    while K > 0:
        p = A[p]
        cnt += 1
        K -= 1
        if p in dic:
            K %= (cnt - dic[p])
        else:
            dic[p] = cnt

    print(p)

if __name__ == '__main__':
    main()
