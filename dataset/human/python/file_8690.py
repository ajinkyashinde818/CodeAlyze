import sys

sys.setrecursionlimit(10 ** 7)
rl = sys.stdin.readline


def solve():
    k, n = map(int, rl().split())
    a = list(map(int, rl().split()))
    d = 0
    for i in range(1, n):
        d = max(d, a[i] - a[i - 1])
    d = max(d, k - a[n - 1] + a[0])
    print(k - d)

    
if __name__ == '__main__':
    solve()
