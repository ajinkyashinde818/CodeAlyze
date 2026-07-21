import sys
def fastio():
    from io import StringIO
    from atexit import register
    global input
    sys.stdin = StringIO(sys.stdin.read())
    input = lambda : sys.stdin.readline().rstrip('\r\n')
    sys.stdout = StringIO()
    register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

def debug(*var, sep = ' ', end = '\n'):
    print(*var, file=sys.stderr, end = end, sep = sep)

INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
# from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br

s = [0] + [int(i) for i in input()]
ans = 0
n = len(s)
for i in range(n - 1, 0, -1):
    x = s[i]
    if x > 5:
        ans += (10 - x)
        idx = i - 1
        s[idx] += 1
        while idx > 0 and s[idx] == 10:
            s[idx] = 0
            s[idx - 1] += 1
            idx -= 1
    elif x == 5 and s[i - 1] >= 5:
        ans += 5
        idx = i - 1
        s[idx] += 1
        while idx > 0 and s[idx] == 10:
            s[idx] = 0
            s[idx - 1] += 1
            idx -= 1
    else:
        ans += x
ans += s[0]
print(ans)
