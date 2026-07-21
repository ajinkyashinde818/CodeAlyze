import sys;input=lambda:sys.stdin.readline().rstrip();aint=lambda:int(input());ints=lambda:list(map(int,input().split()))
import math;floor,ceil=lambda x:int(math.floor(x)),lambda x:int(math.ceil(x))
from functools import reduce;gcd=lambda*x:reduce(math.gcd,x);lcm=lambda*x:reduce(lambda x,y:(x*y)//gcd(x,y),x,1)
from collections import deque
import bisect
Yes=lambda b:print("Yes"if b else"No");YES=lambda b:print("YES"if b else"NO")
is_even=lambda x:True if x%2==0 else False

def main():
    n,k=ints()
    a=ints()
    passed=[]
    flg=0
    p=0
    while flg==0:
        if a[p] == 'passed':
            flg=1
            s=passed.index(p)
            break
        else:
            passed.append(p)
            pp=p
            p=a[pp]-1
            a[pp]='passed'
    l=len(passed)
    if k<l:
        print(passed[k]+1)
    else:
        print(passed[(k-s)%(l-s)+s]+1)

if __name__ == '__main__':
    main()
