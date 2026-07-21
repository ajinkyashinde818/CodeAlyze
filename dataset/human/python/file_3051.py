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
soinsu = factorization(int(input()))
if soinsu[0][0]==1:
  print(0)
  exit()
answer=0
for i in range(len(soinsu)):
  x = soinsu[i][1]
  j = 0
  while x >= 0 :
    j+=1
    x -= j
  else:answer += j-1
print(answer)
