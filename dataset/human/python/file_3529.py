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
fa = factorization(n)
ans = 0
rui = [0]*20
for i in range(1,20):
    rui[i] = i+rui[i-1]


for so,si in fa:
    for i in range(1,20):
        if rui[i]<= si <rui[i+1]:
            ans+= i
            break
print(ans)
