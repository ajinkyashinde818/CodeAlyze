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

    if arr == [[1, 1]]:
        return []
    else:
        return arr

prime_factor = factorization(n)

result = 0

for _, count in prime_factor:
    i = 1
    while count >= i:
        result += 1
        count -= i
        i += 1

print(result)
