import sys
from copy import deepcopy
from math import ceil, floor
from collections import deque, Counter, defaultdict
from fractions import gcd
input = lambda: sys.stdin.readline().rstrip()

def eprint(s):
    sys.stderr.write('DEBUG: {}'.format(s))
    return

def cal(a,b,k):
    return min(abs(a-b), k-abs(a-b))

def cal2(l):
    n = len(l)
    ans = 0
    for i in range(n-1):
        ans += l[i+1] - l[i]
    return ans
def main():
    k,n = map(int, input().split())
    As = list(map(int, input().split()))
    le = list()
    for i in range(n):
        if i == n-1:
            le.append(cal(As[i], As[0] , k) )
        else:
            le.append(As[i+1]- As[i])
    print(k-max(le))
if __name__ == '__main__':
    main()
