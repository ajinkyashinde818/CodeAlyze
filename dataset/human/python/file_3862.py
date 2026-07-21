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
N = int(input())
A = factorization(N)
if N == 1:
  print(0)
  exit()
ans = 0
for a,b in A:
    if b < 3:
        ans += 1
    elif b < 6:
        ans += 2
    elif b < 10:
        ans += 3
    elif b < 15:
        ans += 4
    elif b < 21:
        ans += 5
    elif b < 28:
        ans += 6
    elif b < 36:
        ans += 7
    elif b < 45:
        ans += 8
    else:
        ans += 9
print(ans)
