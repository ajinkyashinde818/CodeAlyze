import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
input=lambda :sys.stdin.readline().rstrip()
def resolve():
    import re
    pattern="^(dream|dreamer|erase|eraser)+$"
    cmp=re.compile(pattern)
    print("YES" if cmp.match(input()) else "NO")
resolve()
