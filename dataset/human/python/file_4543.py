N=int(input())
def fact(n):
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
ans=0  
if N==1:
  print(0)
else:
  for i in range(len(fact(N))):
    j=1
    while fact(N)[i][1]>=j*(j+1)/2:
      j+=1
    ans+=(j-1)
  print(ans)
