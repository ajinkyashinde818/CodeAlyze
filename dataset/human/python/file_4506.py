arr = []
initial = int(input())
temp = initial
for i in range(2, int(-(-temp**0.5//1))+1):
  if temp%i==0:
    cnt=0
    while temp%i==0:
      cnt+=1
      temp //= i
    arr.append(cnt)
if temp!=1:
  arr.append(1)
if arr==[]:
  arr.append(1)

def judge(n):
  l = 1
  while n > 0:
    n -= l
    l += 1
  if n == 0:
    return l-1
  else:
    return l-2

count = 0
for i in arr:
  count += judge(i)

if initial == 1:
  print(0)
else:
  print(count)
