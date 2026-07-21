import sys
if sys.platform == 'ios':
	sys.stdin = open('input_file.txt')
	

n,m = map(int,input().split())

a = [str(input()) for i in range(n)]
b = [str(input()) for i in range(m)]

s = [ [0]*m for i in range(m) ]

ans = 0

for i in range(n-m+1):
	for j in range(n-m+1):
		for k in range(m):
			#print(i,j,k)
			s[k] = a[i+k][j:j+m]
		#print(s)
		
		if s == b :
			#print(i,j,s)
			ans = ans +1

print('Yes' if ans >= 1 else 'No')
