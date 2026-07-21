import sys
d,g=map(int,input().split())
l=[[int(i) for i in l.split()] for l in sys.stdin]
def dfs(x,num,cost,flag):
  if x==len(l):
    return 10**18
  num1=num+l[x][0]*100*(x+1)+l[x][1]
  cost1=cost+l[x][0]
  flag1=flag|(2**x)
  cost3=dfs(x+1,num1,cost1,flag1)
  num2=num
  cost2=cost
  flag2=flag
  cost4=dfs(x+1,num2,cost2,flag2)
  for i in range(len(l),0,-1):
    if 2**(i-1)&flag1>0:
      continue
    if num1>=g:
      break
    if (g-num1+i*100-1)//(i*100)<l[i-1][0]:
      cost1+=(g-num1+i*100-1)//(i*100)
      num1+=((g-num1+i*100-1)//(i*100))*100*i
      break
    else:
      num1+=l[i-1][0]*100*i+l[i-1][1]
      cost1+=l[i-1][0]
  for i in range(len(l),0,-1):
    if 2**(i-1)&flag2>0:
      continue
    if num2>=g:
      break
    if (g-num2+(i*100)-1)//(i*100)<l[i-1][0]:
      cost2+=(g-num2+(i*100)-1)//(i*100)
      num2+=((g-num2+(i*100)-1)//(i*100))*100*i
      break
    else:
      num2+=l[i-1][0]*100*i+l[i-1][1]
      cost2+=l[i-1][0]
  if num1<g:
    cost1=10**18
  if num2<g:
    cost2=10**18
  cost=min(cost1,cost2,cost3,cost4)
  return cost
print(dfs(0,0,0,0))
