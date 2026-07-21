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

l = factorization(n)

ttl = 0
if l == [[1, 1]]:
    ttl = 0
else:
    for m in l:
        x = m[1]
        for i in range(1, x + 1):
            x -= i
            if x >=0:
                ttl += 1
            else:
                break

print(ttl)
