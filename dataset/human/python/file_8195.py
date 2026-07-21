import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def main():
    k,s = LI()
    ans = 0
    for x in range(k+1):
        for y in range(k+1):
            if s-k<=x+y and x+y<=s:
                ans += 1

    print(ans)
main()
