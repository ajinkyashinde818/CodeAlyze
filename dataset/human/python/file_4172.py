def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
 
    if temp!=1:
        arr.append([temp, 1])
 
    if arr==[]:
        arr.append([n, 1])
 
    return arr
 
n = int(input())
if n==1:
  print(0)
else:
  arr = factorization(n)
  trial_list = []
  for p in arr:
    i = p[0]
    j = p[1]
    for k in range(1,j+1):
      trial_list.append(i**k)
  sorted(trial_list)
  cnt=0
  for i in trial_list:
    if n%i==0:
      cnt+=1
      n//=i
  print(cnt)
