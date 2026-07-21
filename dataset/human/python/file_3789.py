N = int(input())

def factorizatio(n):
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

ans = 0
for i in factorizatio(N):
    cnt = i[1]
    a = 0
    b = 0
    for j in range(1, cnt+1):
        a += j            
        if a > cnt:
            break
        b += 1    
    ans += b

print(0 if N == 1 else ans)
