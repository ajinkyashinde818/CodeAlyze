import math
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

n = int(input())
pl = factorization(n)
if len(pl) == 0: exit(print(0))
count = 0
for a,b in pl:
    if a==1 and b==1: exit(print(0))
    t=1
    while True:
        if b < t: break
        count += 1
        b-=t
        t+=1
print(count)
