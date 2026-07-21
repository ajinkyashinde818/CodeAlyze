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

def kirisute(n):
    p=(-1+math.sqrt(1+8*n))/2
    q=math.floor(p)
    return q

N = int(input())

div_arr = factorization(N)
if div_arr[0][0] == 1:
    div_arr.pop(0)

cnt = 0

for a in div_arr:
    cnt += kirisute(a[1])

print(cnt)
