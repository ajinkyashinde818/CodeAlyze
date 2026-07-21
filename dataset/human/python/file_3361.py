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
#print(factorization(N))

ans = factorization(N)
#print(ans)
if ans == [[1,1]]:
    print(0)
else:
    sum = 0
    for i in range(len(ans)):
        n = 1
        while ans[i][1] >= n:
            ans[i][1] -= n
            sum += 1
            n += 1
    print(sum)
