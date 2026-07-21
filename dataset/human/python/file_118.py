from collections import defaultdict
from collections import deque
import itertools
import copy

def readInt():
	return int(input())
def readInts():
	return list(map(int, input().split()))
def readChar():
	return input()
def readChars():
	return input().split()

R,G,B,n = readInts()
ans = 0
for r in range(n//R+2):
	for g in range(n//G+2):
		t = n-(r*R+g*G)
		if t%B==0 and t>=0:
			ans+=1

print(ans)
