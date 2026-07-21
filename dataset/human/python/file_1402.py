import math

n=int(input())
s=0
l=[]

x=input()
x=x.split(' ')


for i in range(n):
  s=s+int(x[i])
  l.append(s)


m = abs(l[0]-(s-l[0]))

for i in range(1,n-1):
  if m > abs(l[i]-(s-l[i])):
    m=abs(l[i]-(s-l[i]))
    
print(m)
