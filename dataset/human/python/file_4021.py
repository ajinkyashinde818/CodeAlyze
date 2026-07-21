N = int(input())

def factorization(n):
    arr = dict()
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr[i] = cnt

    if temp!=1:
        arr[temp] = 1

    if arr==[]:
        arr[n] = 1

    return arr

fact = factorization(N)
cnt = 0

for value in fact.values():
    tmp = 3
    next_num = 3
    tmp_cnt = 1
    while tmp <= value:
        tmp += next_num
        next_num += 1
        tmp_cnt += 1
    

    cnt += tmp_cnt
    
print(cnt)
