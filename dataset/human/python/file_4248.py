n=int(input())
c=0

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

for i in factorization(n):
  for j in range(1,100000):
    if (j-1)*j<=2*i[1]<j*(j+1):
      c+=j-1
if n!=1:
  print(c)
else:
  print(0)
