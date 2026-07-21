def factorization(n):
    arr = []
    temp = n
    if n<2:
        return []
    for i in range(2, int(n**0.5)+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
                arr.append(i**cnt)
    if temp!=1:
        arr.append(temp)

    if arr==[]:
        arr.append(n)
    return arr

N = int(input())
arry = factorization(N)
ans = 0
for a in sorted(arry):
    if N%a==0:
        N //= a
        ans += 1
    if N<=1:
        break
print(ans)
