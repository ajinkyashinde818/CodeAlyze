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
    print(0)
else:
    arr = factorization(N) 
    cnt = 0
    for key in arr:
        tmp = 1
        val = key[1]
        while val > 0:
            if val - tmp > tmp:
                val -= tmp
                tmp += 1
                cnt += 1
            else:
                val = 0
                cnt += 1
            
    print(cnt)
