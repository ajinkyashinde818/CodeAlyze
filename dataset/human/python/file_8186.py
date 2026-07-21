import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
    
k,s=map(int,input().split())
cnt=0

for i in range(k+1):
	a=i
	for j in range(k+1):
		b=j
		if a+b<=s and a+b+k>=s:
			cnt+=1
			
print(cnt)
