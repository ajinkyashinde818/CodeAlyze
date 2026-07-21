import math
N = int(input())
t = 0
p = N
tmp = int(math.sqrt(N)) + 1
for num in range(2,tmp):
    d = 1
    while N % num**d ==0:
        N //= num**d
        t += 1
        d += 1
    if(N % num == 0):
        while N % num == 0:
            N //= num
if (N != 1):
    t+=1
if(t==0 and p != 1):
    t = 1
print(t)
