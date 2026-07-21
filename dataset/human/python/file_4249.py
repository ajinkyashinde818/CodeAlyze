n=int(input())
if n==1:
  print(0)
  exit()
def pf(n):
    a = []
    N = n
    for i in range(2, int(pow(N,0.5)//1+2)):
        if n%i==0:
            count=0
            while n%i==0:
                count+=1
                n //= i
            a.append([i,count])
    if n!=1:
        a.append([n,1])
    if a==[]:
        a.append([n,1])
    return a
l=pf(n)
ans=0
ll=len(l)
for i in range(ll):
  x,y=l[i][0],l[i][1]
  ans+=int((-1+pow(1+8*y,0.5))/2)
print(ans)
