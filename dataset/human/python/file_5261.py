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

d = {}
for i in range(200002):
	d[i]={}

n,m = readInts()
ab = [readInts() for i in range(m)]
for i in ab:
	d[i[0]][i[1]]=1

for i in d[1]:
	if n in d[i]:
		print("POSSIBLE")
		exit()

print("IMPOSSIBLE")
