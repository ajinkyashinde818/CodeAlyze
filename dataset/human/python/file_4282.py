N = int(input())
 
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
 
A = factorization(N)
 
def func(x):
    import math
    return int((-1+math.sqrt(1+8*x))/2)
 
ans = 0
for i in range (len(A)):
    ans = ans + func(A[i][1])
    
if N != 1:
  print(ans)
else:
  print(0)
