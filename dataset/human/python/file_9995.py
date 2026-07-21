import bisect,collections,copy,heapq,itertools,math,string
import sys
import fractions
 
def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)
 
def S(): return sys.stdin.readline().rstrip()
def M(): return map(int,sys.stdin.readline().rstrip().split())
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def LS(): return list(sys.stdin.readline().rstrip().split())
a, b = M()
ans = lcm(a, b)
print(ans)
