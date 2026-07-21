import sys
input = sys.stdin.readline
from operator import itemgetter
sys.setrecursionlimit(10000000)
INF = 10**30

def main():
    n = int(input().strip())
    v = list(map(int, input().strip().split()))
    s = 0
    m = INF
    su = 0
    for i in range(n):
        if v[i] < 0:
            s += 1
        if abs(v[i]) < m:
            m = abs(v[i])
        su += abs(v[i])
    if s % 2 == 0:
        print(su)
    else:
        print(su - 2 * m)

if __name__ == '__main__':
    main()
