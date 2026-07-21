from collections import defaultdict
r=lambda : list(map(int,input().split()))#anonymous function used to take input
n,k=r()
l=r()
d=defaultdict(int) #taking dictionary of each length
d[1]=0
temp=[1]
t=1
loop=-1  
while True:
    t=l[t-1] #jumping based on the value at tth position in the arr
    if t in d: #if t is already in dictionary then we find the array
        loop=d[t] #just take the length of the array
        break    #now break the loop
    d[t]=len(temp)   #t key and value with the length of temp
    temp.append(t)
head=temp[:loop]
rloop=temp[loop:]
if k<loop:
    print(head[k])
else:
    print(rloop[(k-loop)%len(rloop)])
