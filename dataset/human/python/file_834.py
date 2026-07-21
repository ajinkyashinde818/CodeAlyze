import sys
from collections import Counter
from collections import deque
import math
import fractions
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

n,r=mp()
if n>=10:
    print(r)
else:
    print(100*(10-n)+r)
