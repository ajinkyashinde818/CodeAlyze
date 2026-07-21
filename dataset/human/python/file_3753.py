n = int(input())

def factorization(n):
    arr = []
    if n == 1:
        return arr
    tmp = n
    for i in range(2,int(n**0.5)+1):
        if tmp%i == 0:
            cnt = 0
            while tmp%i == 0:
                cnt += 1
                tmp //= i
            arr.append([i,cnt])
    if tmp != 1:
        arr.append([tmp,1])
    if arr == []:
        arr.append([n,1])
    return arr

f_list = factorization(n)    
cnt = 0
for i in range(len(f_list)):
    _tmp = f_list[i][1]
    e = 1
    while _tmp - e >= 0:
        cnt += 1
        _tmp -= e
        e += 1
print(cnt)
