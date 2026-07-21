from collections import defaultdict
from collections import deque
from collections import Counter
import itertools
import math

def readInt():
	return int(input())
def readInts():
	return list(map(int, input().split()))
def readChar():
	return input()
def readChars():
	return input().split()

n = readInt()
a = readInts()

suma = sum(a)
ans = float("inf")
t = 0
for i in range(n-1):
	t += a[i]
	ans = min(ans,abs(suma-t-t))

print(ans)
