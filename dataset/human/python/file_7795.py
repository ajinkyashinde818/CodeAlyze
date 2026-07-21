import sys
input = sys.stdin.readline
from operator import itemgetter
sys.setrecursionlimit(10000000)
INF = 10**30

def main():
    n, k, s = list(map(int, input().strip().split()))
    ans = [str(s)] * k
    for i in range(n-k):
        if s != 10**9:
            ans.append(str(10**9))
        else:
            ans.append(str(1))
    for i in range(n):
        print(ans[i])

if __name__ == '__main__':
    main()
