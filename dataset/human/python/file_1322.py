import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def main():
    n = I()
    a = LI()
    sunuke = 0
    arai = sum(a)
    ans = float("inf")
    for i in range(n-1):
        sunuke += a[i]
        arai -= a[i]
        ans = min(ans,abs(sunuke-arai))

    print(ans)
main()
