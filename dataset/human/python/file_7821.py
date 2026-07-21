def solve(N,K,S):
    """
    >>> solve(4,2,3)
    1 2 3 4
    >>> solve(4,2,1000000000)
    1000000000 1000000000 1 1
    """
    if S < 1000000000:
        l = [str(S)] * K
        for i in range(N-K):
            l.append("1000000000")
        s = " ".join(l)
        print(s)
    else:
        l = [str(S)] * K
        for i in range(N-K):
            l.append("1")
        s = " ".join(l)
        print(s)


def main():
    N,K,S = map(int,input().split())
    solve(N,K,S)


def _test():
    import doctest
    doctest.testmod()


if __name__ == "__main__":
    import sys
    argv = sys.argv
    if len(sys.argv) == 1:
        # no option
        main()
    elif sys.argv[1] == "-t":
        _test()
    else:
        input = open(sys.argv[1]).buffer.readline
