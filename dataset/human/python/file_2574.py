d,g=map(int,input().split())
pc=[]
for _ in range(d):
  pc.append([int(i) for i in input().split()])

def solve(g,i):
  if i==-1:
    return 100000
  n=min(g//(100*(i+1)),pc[i][0])
  s=n*(i+1)*100
  if n==pc[i][0]:
    s+=pc[i][1]
  if g-s>0:
    n+=solve(g-s,i-1)
  return min(n,solve(g,i-1))

print(solve(g,d-1))
