import sys,collections,math,random;sys.setrecursionlimit(10**7)
from fractions import gcd
def Is(): return [int(x) for x in sys.stdin.readline().split()]
def Ss(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

n = I()
if n%2 == 1:
    print(0)
    exit()
lis = []
for i in range(1,26):
    lis.append((n // (5**i))//2 )
print(sum(lis))
