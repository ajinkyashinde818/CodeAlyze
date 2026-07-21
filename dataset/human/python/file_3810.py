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
ans = factorization(N)
index = [ans[i][1] for i in range(len(ans))]
k = 0
if N == 1:
  print('0')
else:
  
  for i in range(len(ans)):
    a = index[i]
    j = 1
    while a - j >=0:
      k += 1
      a -= j
      j += 1
  print(k)
