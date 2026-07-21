import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip.split())
def main():
    s = S()
    t = S()
    sl = list(s)
    tl = list(t)
    sl.sort()
    tl.sort(reverse=True)
    s = "".join(sl)
    t = "".join(tl)
    print("Yes" if s < t else "No")
main()
