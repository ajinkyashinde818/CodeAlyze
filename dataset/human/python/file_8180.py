import itertools
k,s=map(int,input().split())

arr=[]
cnt=0

for x in range(k+1):
  for y in range(x,k+1):
    z=s-x-y
    if y<=z<=k:
      if x==y==z:
        cnt+=1
      elif x==y or y==z or z==x:
        cnt+=3
      else:
        cnt+=6
print(cnt)
