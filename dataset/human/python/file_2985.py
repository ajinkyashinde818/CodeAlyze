def factorization(n):
    arr = {}
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr[i] = cnt

    if temp!=1:
        arr[temp]=1

    if arr==[]:
        arr[n] = 1

    return arr



N = int(input())
fac_dic = factorization(N) 
count = 0


for k,v in fac_dic.items():
  tmp = 1
  while(v >= tmp):
    v = v - tmp
    tmp += 1
    count += 1
  


print(count)
