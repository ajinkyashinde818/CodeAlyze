import sys

n,m=map(int,input().split())
ln=[list(input()) for i in range(n)]
lm=[list(input()) for i in range(m)]

flg=0
for i in range(n-m+1):
  for j in range(n-m+1):
    if ln[i][j:j+m]==lm[0][0:]:
      flg=1
      for k in range(m-1):
        if ln[i+k+1][j:j+m]!=lm[k+1][0:]:
          flg=0
    if flg==1:
      print("Yes")
      sys.exit()
print("No")
