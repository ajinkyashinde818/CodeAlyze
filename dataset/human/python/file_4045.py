import math
n = int(input())

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

d = factorization(n)
ins = []
for i in range(len(d)):
    for j in range(1,d[i][1]+1):
        ins.append(d[i][0]**j)
ins.sort()
cnt = 0
for z in ins:
    if n>1:
        if n%z==0:
            n = n//z
            cnt += 1
    else:
        break
print(cnt)
