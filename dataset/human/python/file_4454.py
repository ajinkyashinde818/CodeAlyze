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

if N == 1:
    print(0)
    exit()
else:
    x =  factorization(N)
    #print(x)


res = 0

for i,j in x:
    cnt = 1
    while  1:
        j -=cnt
        if j < 0: cnt-=1
        if j < 1:
            break
        cnt+=1
    res+=cnt
    cnt = 1

print(res)
