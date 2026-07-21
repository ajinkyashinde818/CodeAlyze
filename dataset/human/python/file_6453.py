import math
from math import ceil
from math import factorial
from collections import Counter
from operator import itemgetter
import bisect
ii = lambda: int(input())
iia = lambda: list(map(int,input().split()))
isa = lambda: list(input().split())
def gcd(a,b):
	if(b==0):
		return a
	return gcd(b,a%b)

n = ii()

if(n%2==1):
	print(0)
else:
	x = len(str(n))
	a = []
	i = 10
	while(i<=n):
		a.append((n//i))
		i*=5
	print(sum(a))
