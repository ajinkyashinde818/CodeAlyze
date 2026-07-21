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
n = int(input())
fact = factorization(n)

cnt = 0
for f in fact:
    fact_num = f[-1] # 何乗か
    tmp = 1  # 1ずつ増やす。
    while True:
        fact_num -= tmp
        #print("fact_num:%d, tmp:%d" % (fact_num,tmp))
        if fact_num >= 0:
            cnt += 1
        else:
            break
        tmp += 1

if n == 1:
    print(0)
else:
    print (cnt)
