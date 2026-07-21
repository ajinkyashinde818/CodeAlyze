import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
   
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n=int(input())

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr
    
a=factorization(n)
le=len(a)
cnt=0
b=0
for i in range(le):
	b=1
	while a[i][1]>=b: 
		a[i][1]-=b
		b+=1
		cnt+=1

if n==1:
	print(0)
else:
	print(cnt)
