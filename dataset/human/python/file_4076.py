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
  ans = 0
else:
  ans = 0
  a = factorization(n)
  for j in a:
    t = j[1]
    if t <= 2:
      ans += 1
    elif t <= 5:
      ans += 2
    elif t <= 9:
      ans += 3
    elif t <= 14:
      ans += 4
    elif t <= 20:
      ans += 5
    elif t <= 27:
      ans += 6
    elif t <= 35:
      ans += 7
    else:
      ans += 8
print(ans)
