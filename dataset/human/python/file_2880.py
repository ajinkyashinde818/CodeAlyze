n=int(input())

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

if n==1:
  print(0)
  exit()  
  
f=factorization(n)
cnt=0
for i in range(len(f)):
  m=2 # 強引
  while f[i][1]>0:
    f[i][1]-=m
    m+=1
    cnt+=1
#    print(f)
print(cnt)
