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
if n == 1:
  print(0)
  quit()
soinsu = factorization(n)
ans = 0
for i in range(len(soinsu)):
  a = 1
  b = 2
  temp = soinsu[i][1]
  num = 0
  while a <= temp:
    a += b
    b += 1
    num +=1
  ans+=num
  
print(ans)
