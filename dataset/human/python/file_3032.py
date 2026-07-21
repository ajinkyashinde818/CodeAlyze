n = int(input())
cnt = 0
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
cnt = 0
for i in arr:
    if i[0] == 1:
        continue
    hiku = 1
    while i[1] > 0:
        i[1] = i[1] - hiku
        if i[1] < 0:
            break
        hiku +=1
        cnt += 1

print(cnt)
