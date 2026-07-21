"""nを素因数分解"""
"""2以上の整数n => [[素因数, 指数], ...]の2次元リスト"""

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

n = int(input())
if(n==1):print(0);exit()
a = factorization(n)
#print(a)
ans = 0
for i in a:
  t = i[1]
  c=1
  tmp = 0
  while(tmp<=t):
    tmp+=c
    c+=1
  ans+=(c-2)
print(ans)
