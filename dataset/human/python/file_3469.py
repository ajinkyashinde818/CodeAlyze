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
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr


ans = 0

if N == 1:
    ans = 0
else:
    l = factorization(N) 
    for i in range(len(l)):
        tmp = 1
        for j in range(40):
            if l[i] >= tmp:
                l[i] -= tmp
                ans += 1
                tmp += 1
            else:
                break
print(ans)
