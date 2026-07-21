import sys,collections as cl
import fractions
from functools import reduce
import copy
Max = sys.maxsize
def l():
	return list(map(int,input().split()))
def m():
	return map(int,input().split())
def s(x):
	a = []
	aa = x[i]
	su = 1
	for i in range(len(x)-1):
		if aa == x[i+1]:
			a.append([aa,su])
			aa = x[i+1]
			su = 1
		else:
			su += 1
	a.append([aa,su])
	return a

n = int(input())
su = 0

a = l()

co = 0
k = 0
a.sort()
f = 0
for i in range(n):
	if a[i] <= 0:
		co += 1
if co % 2 == 0:
	for i in range(n):
		su += abs(a[i])
	print(su)
else:
	for i in range(n):
		if a[i] == 0:
			break
		if a[i] > 0:
			kk = a[i-1]
		if a[i] > 0:
			if abs(a[i-1]) >= a[i]:
				k = a[i]*(-2)
			else:
				k = kk*2
			break
		elif i == n-1:
			k = a[i]*2
	for i in range(n):
		su += abs(a[i])
	su += k
	print(su)
