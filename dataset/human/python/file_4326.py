def factorization(n):
    arr = []
    temp = n
    if n == 1:
        return None
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
if __name__ == "__main__":
    N = int(input())
    A = factorization(N)
    cnt = 0
    if A:
        for a in A:
            b = a[1]
            c = 1
            d = 0
            while(c <= b):
                d += 1
                c += d+1
            cnt += d
    print(cnt)
