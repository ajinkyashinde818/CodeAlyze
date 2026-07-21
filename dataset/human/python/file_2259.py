D,G=map(int,input().split())
pc=[0]+[list(map(int,input().split())) for _ in range(D)]
def f(G,i):
  if i==0:
    return 1e9
  n=min(G//(i*100),pc[i][0])
  s=n*i*100
  if n==pc[i][0]:
    s+=pc[i][1]
  if s<G:
    n+=f(G-s,i-1)
  return min(n,f(G,i-1))
print(f(G,D))
