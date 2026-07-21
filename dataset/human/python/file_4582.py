import itertools

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

#factorization(24) 

## [[2, 3], [3, 1]] 
##  24 = 2^3 * 3^1


t=int(input())
if t==1:
  print(0)
  exit()
  
ans=0
x=factorization(t)


z=[i for i in range(51)]
z=list(itertools.accumulate(z))

for i in range(len(x)):
    cnt=x[i][1]
    for j in range(len(z)):
        if z[j]>cnt:
            ans+=j-1
            break

print(ans)
