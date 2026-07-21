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
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])
    return arr

N = factorization(N)
ans = 0
for p, a in N:
    if p == 1:
        break
    for i in range(1, a+1):
        if i*(i+1) >= 2*a:
            if i*(i+1) == 2*a:
                ans += i
            else:
                ans += (i - 1)
            break

print(ans)
