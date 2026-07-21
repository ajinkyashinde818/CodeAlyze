N = int(input())
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
List = factorization(N)
ans = 0
for i in range(len(List)):
  X = List[i][1]
  j = 1
  num = 0
  if List[i][0] != 1:
    while True:
      X -= j
      j += 1
      if X >= 0:
        num += 1
      else:
        break
    ans += num
  
print(ans)
