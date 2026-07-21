import math
l=[]
def primeFactors(n): 
    while n % 2 == 0: 
        l.append(2)
        n = n / 2         
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            l.append(i)
            n = n / i 
             
    if n > 2: 
        l.append(n)

no=int(input())
d={}
primeFactors(no)
def count(n) : 
    return (-1 + math.sqrt(1 + 8 * n)) // 2; 

for i in range(len(l)):
	if l[i] in d:
		d[l[i]]+=1
	else:
		d[l[i]]=1
c=0
#print(d)
for u,v in d.items():
	c+=count(v)

print(int(c))
