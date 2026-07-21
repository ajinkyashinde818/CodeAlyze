from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
n,k=map(int,input().split())
l=list(map(int,input().split()))
a=1
s=set()
count=0
while a not in s:
	s.add(a)
	a=l[a-1]
	count+=1
	if count==k:
		print(a)
		exit()
if count<k:
	k-=count
	# print(k)
else:
	a=1
	for i in range(k):
		a=l[a-1]
	print(a)
	exit()
s=set()
count=0
while a not in s:
	s.add(a)
	a=l[a-1]
	count+=1
if count<k:
	f=k%count
	for i in range(f):
		a=l[a-1]
	print(a)
else:
	for i in range(k):
		a=l[a-1]
	print(a)
