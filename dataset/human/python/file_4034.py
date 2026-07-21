n = int(input())
if n == 1:
  print(0)
  exit()

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

ans = 0

for p,e in factorization(n):
    tmp = 1
    for i in range(2,60):
        tmp += i
        if e < tmp:
            ans += i-1
            break

print(ans)
