def func(N):
    tmp=N
    arr=[]
    for i in range(2,int((N**0.5//1))+1):
        if tmp%i==0:
            cnt=0
            while tmp%i==0:
                cnt+=1
                tmp//=i
            arr.append([i,cnt])
            
    if tmp!=1 or arr==[]:
        arr.append([tmp, 1])
    return arr

N=int(input())
a=func(N)
ans=0
if a[0][0]==1:
        print(0)
        exit()
        
b=[1,3,6,10,15,21,28,36,45]
for i in a:
    for j in range(len(b)):
       if  i[1]<b[j]:
          ans+=j
          break
print(ans)
