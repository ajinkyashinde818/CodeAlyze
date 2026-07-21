import sys
input = sys.stdin.readline
from operator import itemgetter
sys.setrecursionlimit(10000000)
INF = 10**30

def main():
    n, r = list(map(int, input().strip().split()))
    if n >= 10:
        print(r)
    else:
        print(100*(10-n) + r)

if __name__ == '__main__':
    main()
