import sys
N,k=map(int,input().split())
blist=[0]+list(map(int,input().split()))

checked_list=[-1]*(N+1)
pos=1
t=0
while True:
  if t==k:
    print(pos)
    sys.exit(0)
  elif checked_list[pos]!=-1:
    break
  
  checked_list[pos]=t
  pos=blist[pos]  
  t+=1
  
#print(checked_list,pos,t)
cycle=t-checked_list[pos]
#print(cycle)
pos_in_cycle=(k-checked_list[pos])%cycle
#print(pos_in_cycle)
k2=checked_list[pos]+pos_in_cycle
#print(k2)

print(checked_list.index(k2))
