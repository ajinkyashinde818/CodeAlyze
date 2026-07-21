import sys

def solve():
    n,m = map(int, sys.stdin.readline().split())
    A = [sys.stdin.readline().rstrip() for _ in range(n)]
    B = [sys.stdin.readline().rstrip() for _ in range(m)]
    for r in range(n-m+1):
        for c in range(n-m+1):
            X = []
            for i,a in enumerate(A[r:r+m]):
                if a[c:c+m] != B[i]:
                    break
            else:
                print('Yes')
                exit()
    print('No')

if __name__ == '__main__':
    solve()
