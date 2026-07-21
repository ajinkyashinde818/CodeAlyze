import sys
from io import StringIO
import unittest

def yn(b):
    print("Yes" if b==1 else "No")
    return

def resolve():
    readline=sys.stdin.readline

    k,n=map(int, readline().rstrip().split())
    a=list(map(int, readline().rstrip().split()))

    diff=k-a[-1]+a[0]
    for i in range(1,n):
        diff=max(diff,a[i]-a[i-1])
    print(k-diff)

    return

if 'doTest' not in globals():
    resolve()
    sys.exit()
