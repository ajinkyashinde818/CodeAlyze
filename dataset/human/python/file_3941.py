import math
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
if N == 1:
  print(0)
  exit()
cnt = 0
insulist = factorization(N)
for i in range(len(insulist)):
  for j in range(1, insulist[i][1] + 1):
    if N % (insulist[i][0] ** j) == 0:
      N //= insulist[i][0] ** j
      cnt += 1
print(cnt)
