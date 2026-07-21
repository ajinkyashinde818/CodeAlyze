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
def f(n):
  for i in range(50,-1,-1):
    if n>=(i*(i+1)//2):
      return i
      break
n=int(input())
cnt=0
alist=factorization(n)
for i in range(len(alist)):
  cnt+=f(alist[i][1])
if n==1:
  cnt=0
print(cnt)
