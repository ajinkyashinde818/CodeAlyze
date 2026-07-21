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

def count_sums(n):
    c = 1    
    while True:
        if n - c < 0:
            break
        n -= c
        c += 1
    return c - 1

N = int(input())
if N == 1:
    print(0)
else:
    # p_N : 素因数分解の結果
    p_N = factorization(N)
    if p_N == [N, 1]:
        print(1)
    else:
        count = 0
        for arr in p_N:
            count += count_sums(arr[1])
        print(count)
