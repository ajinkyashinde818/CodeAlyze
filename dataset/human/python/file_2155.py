import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def main():
    n = I()
    s = S()
    ans = 1
    num = 10**9 + 7
    count = collections.Counter(s)

    for value in count.values():
        ans *= value+1
        ans %= num

    ans -= 1
    ans % num
    print(ans)
        
main()
