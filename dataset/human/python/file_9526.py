def main():
    import sys
    sys.setrecursionlimit(10 ** 7)

    N, K = map(int, input().split())
    *A, = (int(x) - 1 for x in input().split())

    rs = [-1] * N

    def dfs(cur=0, rest=K):
        if ~rs[cur]:
            loop_range = rs[cur] - rest
            rest %= loop_range

        if rest == 0:
            return cur + 1  # -> 1-ind

        rs[cur] = rest
        return dfs(A[cur], rest - 1)

    print(dfs())


if __name__ == '__main__':
    main()
