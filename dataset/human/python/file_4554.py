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
n_list = factorization(n)
oh = []
for i in range(len(n_list)):
  num = n_list[i][0] #2の
  kata = n_list[i][1] #3乗
  for i in range(1, kata+1):
    oh.append(num ** i)
oh.sort()
ans = 0
z = []
for i in range(len(oh)):
  if oh[i] == 1:
    break
  else:
    if n % oh[i] == 0 and oh[i] not in z:
      z.append(oh[i])
      n = n / oh[i]
      ans += 1
print(ans)
