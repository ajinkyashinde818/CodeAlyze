import sys
input=sys.stdin.buffer.readline
from math import*

n=int(input())
arr=list(map(int,input().split()))
brr=list(map(int,input().split()))
crr=list(map(int,input().split()))

ans=0
for i in range(n):
	if i!=0 and arr[i]==arr[i-1]+1:
			ans+=brr[arr[i]-1]+crr[arr[i-1]-1]
	else:
		ans+=brr[arr[i]-1]
print(ans)
