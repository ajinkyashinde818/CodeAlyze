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

n,k,s = readInts()
for i in range(k):
	print(s, end=" ")
for i in range(n-k):
	print(min(10**9-1,s+1),end=" ")
print()
