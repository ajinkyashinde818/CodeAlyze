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

  
def count(n):
  ans = ((1 + 8 * n) ** (1 / 2) - 1) // 2
  return int(ans)
  
N = int(input())
ans = 0
X = factorization(N)
if N == 1:
  print("0")
  quit()
for i in range(len(X)):
  ans += count(X[i][1])
  
print(ans)
