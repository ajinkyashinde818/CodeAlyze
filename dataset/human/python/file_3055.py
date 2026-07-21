n = int(input())
def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
                
            arr.append(cnt)

    if temp != 1:
        arr.append(1)
        
    if arr==[] and n != 1:
        arr.append(1)

    return arr
  
lst = factorization(n)
ans = 0
if not lst:
  print(ans)
else:
  mx = max(lst)
  for _ in lst:
    for i in range(1, mx+1):
      if _ - i >= 0:
      	_ -= i
      	ans += 1
      else:
      	break
  print(ans)
