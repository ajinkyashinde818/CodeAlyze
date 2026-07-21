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
def main():
  N = int(input())
  l = fac(N)
  counter = 0
  if N == 1:
    print(0)
    exit()
  if len(l) == 1 and l[0][1] == 1:
    print(1)
    exit()
  for x in l:
#    print(x)
    temp = 0
    for k in range(1, 141423):
      temp += 1
      z = x[0] ** temp
#      print("z:" + str(z))
      if N/z < 1:
        break
#      print("OK")
      N = N/z
      if float(N).is_integer() == False:
        N = N * z
        break
#      print("z:" + str(z) + ", N:" + str(N))
      counter += 1
    if N <= 1:
      break
  print(counter)
if __name__ == "__main__":
  main()
