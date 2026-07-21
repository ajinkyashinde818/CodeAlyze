import itertools
r,g,b,n = map(int,input().split())
r_max,g_max,b_max = int(n/r),int(n/g),int(n/b)
ans = 0
for i,j in itertools.product(range(0,r_max+1),range(0,g_max+1)):
  if (n - (i*r+j*g))%b == 0 and n - (i*r+j*g) >= 0:
    ans+=1
print(ans)
