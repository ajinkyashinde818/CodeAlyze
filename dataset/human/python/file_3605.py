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

N = int(input())
if N ==1:
  print(0)
  exit()
N_list = factorization(N)
cnt_1 = 0
for i in range(len(N_list)):
  x = 1
  y = N_list[i][1]
  cnt = 0
  while True:
    y -= x
    x += 1
    if y >= 0:
      cnt += 1
    else:
      break
  cnt_1 += cnt 
print(cnt_1)
