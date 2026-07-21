import math
def f(n):
    if n==1:
        return [[1,0]]
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
n=f(int(input()))
s=0
for i in n:
    p=i[1]
    s+=int((-1+math.sqrt(1+8*p))/2)
print(s)
