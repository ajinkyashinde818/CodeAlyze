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
ans = 0
fn = factorization(N)
for i in range(len(fn)):
  if 0 < fn[i][1] <= 2:
    ans += 1
  elif 2 < fn[i][1] < 6:
    ans += 2
  elif 5 < fn[i][1] < 10:
    ans += 3
  elif 10 <= fn[i][1] < 15:
    ans += 4
  elif 15 <= fn[i][1] < 21:
    ans += 5
  elif 21 <= fn[i][1] < 28:
    ans += 6
  elif 28 <= fn[i][1] < 36:
    ans += 7
  elif 36 <= fn[i][1] < 45:
    ans += 8
  elif 45 <= fn[i][1] < 55:
    ans += 9

if N == 1:
  print(0)
else:
  print(ans)
