def fac(n):
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
result=0
flg=0
for i in range(len(fac(n))):
  target = fac(n)[i][1]
  if fac(n)[i][0] <= 1:
    flg=1
    break
  sikii=0
  for j in range(1,target+1):
    sikii += j
    if sikii <= target < (sikii+j+1):
      result += j
      break
if flg == 1:
  print('0')
else:
  print(result)
