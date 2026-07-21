N= int(input())
       
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

if N != 1:  
 listA=factorization(N) 
 nagasa=len(listA)
 nn=0
 kk=1
 count=0
 while nn<nagasa:
   while kk*(kk+1)/2 <=listA[nn][1]:
     count=count+1
     kk=kk+1
   kk=1
   nn=nn+1
 print(count)
if N==1:
  print(0)
