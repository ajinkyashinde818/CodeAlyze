N=int(input())
def divisor_enu(N):
   l=[]
   for i in range(2,int(N**0.5)+1):
      cnt=0
      if N%i==0:
         while N%i==0:
            cnt+=1
            N//=i
         l.append(cnt)
   if N != 1:
      l.append(1)
   return l
l=divisor_enu(N)
ans=0
for i in l:
   for j in range(1,11):
      if i >= (1+j)*j//2:
         ans+=1
print(ans)
