import sys
from math import ceil
INPUT = lambda: sys.stdin.readline().rstrip()
MAP = lambda: map(int, INPUT().split())
LIST = lambda: list(map(int, INPUT().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')

D, G = MAP()
PC = [LIST() for _ in range(D)]


def dfs(g, i):
    if i <= 0: return INF
    n = min(ceil(g/(100*i)), PC[i-1][0])
    s = 100 * i * n
    if n == PC[i-1][0]: s += PC[i-1][1]
    if g > s: n += dfs(g-s, i-1)

    return min(n, dfs(g, i-1))


def main():
    print(dfs(G, D))


if __name__ == '__main__':
    main()
