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

def debug(*var):
    print(*var, file=sys.stderr)

INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
# from math import gcd
# from collections import defaultdict as dd, Counter
# from bisect import bisect_left as bl, bisect_right as br

n, = I()
if n % 2:
    print(0)
    exit()

n //= 2
ans = 0
for i in range(1, 100):
    ans += n//(5**i)
print(ans)
