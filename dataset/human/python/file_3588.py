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
 
    if temp!=1: #素数の場合はここ
        arr.append([temp, 1])
 
    if arr==[]: #1の場合はここ
        arr.append([n, 1])
 
    return arr

def count(X):
  cnt = 0
  now = 1
  while cnt+now <=X:
    cnt += now
    now += 1
  return now-1
#print(count(3))    

N = int(input())
if N == 1:
  print(0)
  exit()
A = factorization(N)
#print(A)
ans = 0
for i in range(len(A)):
  ans += count(A[i][1])
print(ans)
