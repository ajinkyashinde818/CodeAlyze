n,m = map(int,input().split())
a = [list(input()) for i in range(n)]
b = [list(input()) for i in range(m)]
def check(x,y):
    ans = True
    for i in range(m):
        for j in range(m):
            if b[i][j] != a[i+x][j+y]:
                ans = False
    return ans

for i in range(n-m+1):
  for j in range(n-m+1):
      if check(i,j):
          print("Yes")
          exit()
print("No")
