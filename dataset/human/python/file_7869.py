import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def main():
    n,k,s = LI()
    ans = []
    if s<10**9:
        ans = [s]*k + [s+1]*(n-k)
    else:
        if n == k:
            ans = [s]*n
        else:
            for i in range(n):
                if i<=k:
                    ans.append(1 if i%2==0 else s-1)
                else:
                    ans.append(2)
    print(*ans)
    
main()
