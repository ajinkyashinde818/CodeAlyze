N = int(input())

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

A = factorization(N)

if len(A)==0 or N==1:
    print(0)
else:    
    c = 0
    for a in A:
        x = a[1]
        s = 0
        for j in range(1, x+1):
            if s + j <= x:
                c +=1
                s += j
            else:
                break
    print(c)
