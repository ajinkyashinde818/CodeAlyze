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

arr = factorization(n)



l = []

for a, b in arr:
   temp = 1
   for i in range(1,b+1):
       temp *= a
       l.append(temp)

cnt = 0
for i in l:
    if n % i == 0:
        n = int(n/i)
        cnt += 1
    
   
print(cnt)
