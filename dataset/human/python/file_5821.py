import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
    
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))

cnt=0
cnt2=0
for i in range(0,n):
	cnt+=b[i]	
	
for j in range(0,n-1):
	if a[j]+1==a[j+1]:
		cnt2+=c[a[j]-1]
	
print(cnt+cnt2)
