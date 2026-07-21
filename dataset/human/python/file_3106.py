N = int(input())
if N == 1:
  print(0)
  import sys
  sys.exit()

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
  
insu = factorization(N)
sum = 0
for i in insu:
  k = i[1]
  tmp = 0
  while True:
    if tmp*(tmp+1)/2 <= k and k < (tmp+2)*(tmp+1)/2:
      break
    tmp += 1
  sum += tmp
    
print(sum)
