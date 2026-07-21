N = int(input())
L = [int(i) for i in input().split()]
import sys

if(0 in L):
    print(sum(list(map(abs,L))))
    sys.exit()

count=0
min=abs(L[0])
for i in range(N):
    if(L[i]<0):
        count+=1
    if(abs(L[i])<min):
        min=abs(L[i])

#print(count,min)

if(count%2==0):
    print(sum(list(map(abs,L))))
else:
    print(sum(list(map(abs,L)))-(2*min))
