import sys

sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

def main():
    N, K = map(int, readline().split())
    A = list(map(int, readline().split()))
    lenA = len(A)

    tmp = []
    path = []
    setpath = set([])
    cnt = 0
    i = 1
    for _ in range(1, N+10):
        setpath.add(i)
        path.append(i)
        if len(setpath) != len(path):
            path.pop()
            itmp = path.index(i)
            break
        i = A[i-1]

    lenpath = len(path)
    if K >= lenpath:
        jtmp = (K-itmp)%(lenpath-itmp)
        ans = path[itmp+jtmp]
    else:
        ans = path[K]
    print(ans)


if __name__ == "__main__":
    main()
