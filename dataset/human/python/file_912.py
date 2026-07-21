from numpy import *
n,c = (int(i) for i in input().split())  
xs = []
ys = []

for j in range(n):
  x,y = (int(i) for i in input().split())  
  xs.append(x)
  ys.append(y)
left = [[0,0]]
right = [[0,0]]
lmax = [0]
rmax = [0]
for j in range(n):
  left.append([left[-1][0]+ys[j]-(xs[j]-left[-1][1]),xs[j]])
  lmax.append(max(lmax[-1],left[-1][0]))

for j in range(n)[::-1]:
  right.append([right[-1][0]+ys[j]-(right[-1][1]+c-xs[j]),xs[j]-c])
  rmax.append(max(rmax[-1],right[-1][0]))
anss = []
anss.append(max(lmax))
anss.append(max(rmax))
for i in range(1,n):
  anss.append(left[i][0]-xs[i-1]+rmax[-1-i])  
for i in range(1,n):
  anss.append(right[i][0]+right[i][1]+lmax[-1-i])
print(max(anss))
