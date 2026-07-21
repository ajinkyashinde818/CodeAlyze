def factorization(n):
    arr = []
    temp = n
    for i in range(2, int((n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
                arr.append(i ** cnt)

    if temp != 1:
        arr.append(temp)

    if arr == []:
        arr.append(n)

    return arr

ans = 0
X = int(input())
Y = factorization(X)
Y.sort()
Z = X
for i in range(len(Y)):
  if X % Y[i] == 0:
    ans += 1
    X /= Y[i]
    
if Z == 1:
  print(0)
else:
  print(ans)
