N=int(input())
A=[int(x) for x in input().split()]

def solve(li,n):
  cnt=sum(li)
  s=((n+1)*n)//2
  if cnt % s !=0:
    print("NO")
    return
  
  cnt//=s
  
  ch=[cnt for x in range(n)]
  res=[]
  for i in range(n-1):
    res.append(li[i+1]-li[i])
  res.append(li[0]-li[-1])
  
  for i in range(n):
    if ch[i] != res[i]:
      if abs(ch[i]-res[i]) % n !=0:
        print("NO")
        return
      else:
        cnt-=abs(ch[i]-res[i])//n
  if cnt==0:
    print("YES")
    return
  else:
    print("NO")
    return

solve(A,N)
