def fanction(n):
    listIn = []
    tmp = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
        if tmp % i == 0:
            cnt_in = 0
            while tmp % i ==0:
                cnt_in += 1
                tmp //= i
            listIn.append([i, cnt_in])
 
    if tmp != 1:
        listIn.append([tmp, 1])
 
    return listIn
    
N = int(input())
 
arr = fanction(N)
 
tmp = 1
count = 0
for a, b in arr:
    while 'true':
        if b >= tmp:
            b -= tmp
            count += 1
            tmp += 1
        else:
            tmp = 1
            break
 
print(count)
