d,g = map(int,input().split())
pc = [list(map(int,input().split())) for _ in range(d)]
ans = float("inf")
def bfs(i,solve,sum,n):
  if i == d:
    if sum>=g:
      global ans
      ans = min(ans,solve)
    elif (pc[n][0]-1)*(n+1)*100 >= g-sum:
      if (g-sum) % ((n+1)*100) == 0:
        plus = (g-sum) // ((n+1)*100)
      else:
        plus = (g-sum) // ((n+1)*100) + 1 
      ans = min(ans,solve+plus)
  else:
    bfs(i+1,solve+pc[i][0],sum+pc[i][0]*(i+1)*100+pc[i][1],n)
    bfs(i+1,solve,sum,i)
bfs(0,0,0,0)
print(ans)
