A = int(input())

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

B = factorization(A)
N = len(B)
ans = 0
for n in range(N):
  m =1
  b = B[n][1]
  while b >= ((m+1)*(m+2)//2):
    m+=1
  ans += m
if A==1:
  print(0)
else:
  print(ans)
