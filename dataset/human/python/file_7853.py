import sys
from pprint import pprint

def solve(n, k, s):
    a = [0] * n
    for i in range(n):
        if i < k:
            a[i] = s
        else:
            if s == 10**9:
                a[i] = s-1
            else:
                a[i] = s+1
    print(" ".join(map(str,a)))


if __name__ == '__main__':
    n, k, s = map(int, sys.stdin.readline().strip().split(" "))
    solve(n, k, s)
