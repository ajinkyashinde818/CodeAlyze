N=int(input())
import bisect

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
if N==1:
  print(0)
else: 
	count=0  
	k=[1,3,6,10,15,21,28,36,45,55]
	l=factorization(N)
	#print(l)
	for i in l:
  		q=bisect.bisect(k,i[1])
  		count+=q
  
	print(count)
