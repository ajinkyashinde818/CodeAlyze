import copy
K,N = (int(x) for x in input().split())
a = list(map(int,input().split()))
b = copy.copy(a)
tmp = a[N-1]
for i in range(N-1):
  a[i+1] -= a[i]
a[0] += K-tmp
d1 = sum(a)-max(a)
b = b[::-1]
tmp =b[0] 
for i in range(N-1):
  b[i] -= b[i+1] 
b[N-1] += K-tmp
d2 = sum(b)-max(b)
print(min(d1,d2))
