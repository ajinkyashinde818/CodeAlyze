import bisect
n = int(input())
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

N = factorization(n) 
t = [1]
ans = 0
if N == [[1,1]]:
  print(ans)
else:
  for i in range(2,10**5):
    t.append(t[i-2]+i)
  for j in range(len(N)):
    s = bisect.bisect_right(t, N[j][1])
    ans += s
  print(ans)
