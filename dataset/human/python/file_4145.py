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
e = factorization(n)
cnt = 0
if n != 1:
  for i in range(len(e)):
    curr_num = e[i][1]
    curr_val = 1
    while curr_val * (curr_val + 1) / 2 < curr_num:
      curr_val += 1
    if curr_val * (curr_val + 1) / 2 > curr_num:
      curr_val -= 1
    cnt += curr_val

print(cnt)
