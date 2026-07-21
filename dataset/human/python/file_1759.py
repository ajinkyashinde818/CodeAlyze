def main():
  num = list(map(int,input().split()))
  n=num[0]
  m=num[1]
  a = [input() for i in range(n)]
  b = [input() for i in range(m)]

  flg=0
  
  for i in range(0 , n):
    if m==1 and a[i].find(b[0])!=-1:
      flg=1
      break
    while n-i >= m and a[i].find(b[0])!=-1:
      start=a[i].find(b[0])
      for j in range(1 , m):
        if a[i+j][start:start+m]!=b[j]:
          break
        if j==m-1:
          flg=1
      if flg==1:
        break
      a[i]=a[i][a[i].find(b[0])+1:]
    if flg==1:
        break
        
  if flg==1:
    print("Yes")
  else:
    print("No")

main()
