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
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

whole = factorization(n)

count = 0

if whole == [[1, 1]]:
  print(count)
  exit()

#print(whole)
for s in whole:
  #print(s)
  c = 0
  for i in range(1, s[1] + 1):
    shou = n / (int(s[0]) ** (i * (i + 1) / 2))
    seisuu = n // (int(s[0]) ** (i * (i + 1) / 2))
    if shou == seisuu:
      #print(shou, seisuu)
      c += 1
    else:
      break
  count += c

print(count)
