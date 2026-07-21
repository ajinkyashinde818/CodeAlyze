def fact(n):
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

a = int(input())
li = []
li = fact(a)
count = 0
i = 0
dif = 1

while i < len(li):
    if a == 1:
        break
    
    if li[i][1] >= dif:
        count += 1
        li[i][1] -= dif
        dif += 1
    else:
        dif = 1
        i += 1
print(count)
