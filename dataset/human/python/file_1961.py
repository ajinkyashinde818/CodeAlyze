def grinp(h):
  ret=[]
  for i in range(h):
    ret.append(list(input()))
  return ret
n,m=map(int,input().split())
ngr=grinp(n)
mgr=grinp(m)

for i in range(n-m+1):
  for j in range(n-m+1):
    flag=True
    for k in range(m):
      for l in range(m):
        if ngr[i+k][j+l]!=mgr[k][l]:
          flag=False
          break
      if not flag:
        break
    if flag:
      print("Yes")
      break
  if flag:
    break
else:
  print("No")
