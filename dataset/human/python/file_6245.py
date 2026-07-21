import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7 # 998244353
input=lambda:sys.stdin.readline().rstrip()
def resolve():
    just, less = 0, INF
    for d in input()[::-1]:
        d = int(d)
        njust = min(just + d, less + d + 1)
        nless = min(just + (10-d), less + (9-d))
        just, less = njust, nless
    print(min(just, less + 1))
resolve()
