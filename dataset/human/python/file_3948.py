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

if N == 1:
    print("0")
    exit()

temp = factorization(N)

ans = 0

def counter(num):
    count = 0
    time = 1
    while num > 0:
        num = num - time
        count += 1
        time += 1
        
    if num == 0:
        return count
    if num < 0:
        return count - 1

for i in range(len(temp)):
    ans += counter(temp[i][1])
    
print(ans)
