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
count = 0
primelist = factorization(n)
#print(primelist)

if primelist[0][0]==1:
  print(0)
else:
  for i in range(len(primelist)):
    for j in range(40):
      if j*(j+1)/2 > primelist[i][1]:
        count += (j-1)
        break
  print(count)
