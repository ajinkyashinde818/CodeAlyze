n=int(input())

z=[]

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

f=factorization(n)

count=0
for i in f:
  if i[0]==1:
    pass
  else:
    a=i[1]
    c=1
    while True:
      if a>=c:
        a-=c
        count+=1
        c+=1
      else:
        break
      
print(count)
