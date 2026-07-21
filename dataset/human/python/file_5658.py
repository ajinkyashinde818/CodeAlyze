import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def main():
    
    s = S()

    ex = s.replace("x", "")

    for i in range(len(ex)//2):
        if ex[i] != ex[len(ex)-1-i]:
            print(-1)
            exit(0)

    
    l = -1
    r = len(s)
    ans = 0

    while True:
        l += 1
        r -= 1
        lcnt = 0
        rcnt = 0

        while l < len(s):
            if s[l] == "x":
                lcnt += 1
                l += 1
            else:
                break

        while r > -1:
            if s[r] == "x":
                rcnt += 1
                r -= 1
            else:
                break

        if l > r:
            break
        ans += abs(lcnt-rcnt)

    print(ans)
    
main()
