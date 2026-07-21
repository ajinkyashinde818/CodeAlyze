import bisect

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

kosu=[i*(i+1)//2 for i in range(60)]
#print(kosu)
n=int(input())
pnum=factorization(n) 
ans=0
for i in range(len(pnum)):
  kata=pnum[i][1]
  tmp=bisect.bisect_left(kosu,kata)-1
  if kata in kosu:
    tmp+=1
  ans+=tmp
  #print("tmp",tmp,ans)
if n==1:
  ans=0
print(ans)
