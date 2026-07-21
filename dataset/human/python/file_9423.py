import sys

n,k = map(int,input().split())
a = list(map(int,input().split()))

array = [-1] * (n+1)
array[1] = 0

li = []
li.append(1)

tmp = -1
index = 0
for i in range(2 * (10**5)):
  if array[a[index]] != -1:
    tmp = array[a[index]]
    break
    
  if i == k:
    print(index+1)
    sys.exit(0)
    
  li.append(a[index])
  array[a[index]] = i+1
  index = a[index] -1
  
k -= tmp
d = len(li) - tmp

k %= d

print(li[k+tmp])
