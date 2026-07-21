n=int(input())

def factorization(n):
    global a
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

soinsu = factorization(n)
a = len(soinsu)
#print(soinsu)
#print(a)
ans = 0

for i in range(a):
    x = soinsu[i][1]
    for j in range(1,10**18):
        if x >= j:
            x = x-j
            ans += 1
        else:
            break

if n== 1:
    ans = 0


print (ans)
