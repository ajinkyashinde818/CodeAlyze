n=int(input())

import math

def factorization(n): #nを素因数分解する
    arr = []
    temp = n
    for i in range(2, int(math.sqrt(n))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

#    if arr==[]:
#        arr.append([n, 1])  #n=1でarr=[1,1]としたいとき

    return arr

z=factorization(n)

ans=0
for i in range(len(z)):
    for j in range(1,z[i]+1):
        if (z[i]-j)>=0:
            z[i]-=j
            ans+=1
        else:
            break
print(ans)
