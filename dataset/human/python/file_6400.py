import sys
import  math
import fractions
from collections import defaultdict
stdin = sys.stdin
     
ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

N=int(input())

if(N%2==1):
    print(0)
    sys.exit()

else:
    ans=0
    for i in range(1,36):
        ans+=((N//2)//(5**i))
    print(ans)
