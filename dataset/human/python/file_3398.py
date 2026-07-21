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
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr

arr = factorization(N)
if N==1:
  arr = []
def solv(c):
    D = (1 - 8*(-c)) ** (1/2)
    x_1 = (-1 + D) / 2
    x_2 = (-1 - D) / 2
    
    return int(max(x_1, x_2))
ans = 0
for i in arr:
  ans += solv(i)

print(ans)
