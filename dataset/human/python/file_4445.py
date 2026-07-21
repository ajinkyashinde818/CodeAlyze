import collections
N = int(input())
root = int(N**0.5+3)
l = [0] * root
t = [0] * root
c = [0] * root
for i in range(2,root):
    while N % i ==0:
        N = N/i
        l[i] +=1
    t[i] = l[i]
        
    j = 1
    while l[i]- j >=0:
        l[i] =l[i] - j
        j = j +1
        
    c[i] = j -1

if N >1:
    a = 1
else:
    a =0
    
#print(t)
#print(l)

print(sum(c)+a)
