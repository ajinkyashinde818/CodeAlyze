n = int(input())

"""nを素因数分解"""
"""2以上の整数n => [[素因数, 指数], ...]の2次元リスト"""

def fac(n):
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
  
list = fac(n)
count = 0
for l in list:
  c = 0
  sum = 0
  while True:
    c += 1
    sum += c
    if l[1]<sum:
      break
    count += 1

if n == 1:
  print(0)
else:
  print(count)
