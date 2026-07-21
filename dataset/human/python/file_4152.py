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

def rui(x):
  if x<3:
    return 1
  elif x<6:
    return 2
  elif x<10:
    return 3
  elif x<15:
    return 4
  elif x<21:
    return 5
  elif x<28:
    return 6
  elif x<36:
    return 7
  else:
    return 8
  
N=int(input())
A=factorization(N) 
ans=0
for i in range(len(A)):
  ans+=rui(A[i][1])
if N==1:
  print(0)
else:
  print(ans)
