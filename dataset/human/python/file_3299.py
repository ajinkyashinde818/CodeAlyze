def seachPrimeNum(N):
    max = int(N ** (1/2))
    seachList = [i for i in range(2,N+1)]
    primeNum = []
    while seachList[0] <= max:
        primeNum.append(seachList[0])
        tmp = seachList[0]
        seachList = [i for i in seachList if i % tmp != 0]
    primeNum.extend(seachList)
    return primeNum

a = seachPrimeNum(10 ** 6)
n=(int)(input())
ans = 0
sumi = True
if n < 2:
  print(ans)
  sumi = False
else:
  ans = 0
  count = 0
  while(count < 78498):
    temp = 0
    while(n % a[count] == 0):
      n = n // a[count]
      temp += 1
    if temp >= 45:
      ans += 9
    elif temp >= 36:
      ans += 8
    elif temp >= 28:
      ans += 7
    elif temp >= 21:
      ans += 6
    elif temp >= 15:
      ans += 5
    elif temp >= 10:
      ans += 4
    elif temp >= 6:
      ans += 3
    elif temp >= 3:
      ans += 2
    elif temp >= 1:
      ans += 1
    
    count += 1
    temp = 0
    if n < 2:
      print(ans)
      sumi = False
      break
  if count == 78498 and sumi:
      print(1 + ans)
#print(a[-100])
