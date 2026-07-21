import sys
readline=sys.stdin.readline
 
N = int(readline())
if N == 1:
  print(0)
  exit(0)

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
  
# 同じ素数の組から、1つ、2つと選び方を変えて選ぶ

arr = factorization(N)
ans = 0
for a in arr:
  facts = a[1]
  i = 1
  while i <= facts:
    ans += 1
    facts -= i
    i += 1
print(ans)
