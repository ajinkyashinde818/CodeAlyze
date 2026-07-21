import sys
import itertools
if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
    
k,n=map(int,input().split())

a=list(map(int,input().split()))

c=k-(a[n-1]-a[0])

for i in range(0,n-1):
	c=max(c,a[i+1]-a[i])
	

print(k-c)
